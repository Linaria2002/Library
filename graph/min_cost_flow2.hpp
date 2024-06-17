class min_cost_flow2{
    using edge = struct{ int to, cap, cost, rev; };
    const int64_t Inf = 100100100100100100;
    int N;
    vector<vector<edge>> G;
    vector<int64_t> dist;
    vector<int> prev_v, prev_e;

    public:
    min_cost_flow2(int n) : N(n), G(n), dist(n), prev_v(n), prev_e(n) {}

    void add_edge(int from, int to, int cap, int cost){
        G[from].emplace_back(edge{to, cap, cost, (int)G[to].size()});
        G[to].emplace_back(edge{from, 0, -cost, (int)G[from].size() - 1});
    }

    // bellman-ford
    int solve(int s, int t, int f){
        int res = 0;

        while(f > 0){
            fill(dist.begin(), dist.end(), Inf);
            dist[s] = 0;
            bool update = 1;

            while(update){
                update = 0;
                for(int v = 0; v < N; v++){
                    if(dist[v] == Inf) continue;
                    for(int i = 0; i < (int)G[v].size(); i++){
                        edge &e = G[v][i];
                        if(e.cap > 0 && dist[e.to] > dist[v] + e.cost){
                            dist[e.to] = dist[v] + e.cost;
                            prev_v[e.to] = v;
                            prev_e[e.to] = i;
                            update = 1;
                        }
                    }
                }
            }

            if(dist[t] == Inf) return -1;

            int d = f;
            for(int v = t; v != s; v = prev_v[v]){
                d = min((int64_t)d, G[prev_v[v]][prev_e[v]].cap);
            }
            f -= d;
            res += d * dist[t];
            for(int v = t; v != s; v = prev_v[v]){
                edge &e = G[prev_v[v]][prev_e[v]];
                e.cap -= d;
                G[v][e.rev].cap += d;
            }
        }
        return res;
    }
};