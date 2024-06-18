class min_cost_flow{
    using edge = struct{ int to, cap, cost, rev; };
    using P = pair<int64_t, int>;
    const int64_t MF_INF = 100100100100100100;
    int N;
    vector<vector<edge>> G;
    vector<int64_t> h;
    vector<int64_t> dist;
    vector<int> prev_v, prev_e;

    public:
    min_cost_flow(int n) : N(n), G(n), h(n), dist(n), prev_v(n), prev_e(n) {}

    void add_edge(int from, int to, int cap, int cost){
        G[from].emplace_back(edge{to, cap, cost, (int)G[to].size()});
        G[to].emplace_back(edge{from, 0, -cost, (int)G[from].size() - 1});
    }

    // dijkstra
    int solve(int s, int t, int f){
        int res = 0;
        fill(h.begin(), h.end(), 0);

        while(f > 0){
            priority_queue<P, vector<P>, greater<P>> que;
            fill(dist.begin(), dist.end(), MF_INF);
            dist[s] = 0;
            que.push(P{0, s});

            while(!que.empty()){
                P p = que.top(); que.pop();
                int u = p.second;
                if(dist[u] < p.first) continue;
                for(int i = 0; i < (int)G[u].size(); i++){
                    edge &e = G[u][i];
                    if(e.cap > 0 && dist[e.to] > dist[u] + e.cost + h[u] - h[e.to]){
                        dist[e.to] = dist[u] + e.cost + h[u] - h[e.to];
                        prev_v[e.to] = u;
                        prev_e[e.to] = i;
                        que.push(P{dist[e.to], e.to});
                    }
                }
            }

            if(dist[t] == MF_INF) return -1;
            for(int i = 0; i < N; i++) h[i] += dist[i];

            int d = f;
            for(int v = t; v != s; v = prev_v[v]){
                d = min((int)d, G[prev_v[v]][prev_e[v]].cap);
            }
            f -= d;
            res += d * h[t];
            for(int v = t; v != s; v = prev_v[v]){
                edge &e = G[prev_v[v]][prev_e[v]];
                e.cap -= d;
                G[v][e.rev].cap += d;
            }
        }
        return res;
    }
};