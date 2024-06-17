struct SPFA{
    using Pr = pair<int64_t, int>;
    int N;
    const int64_t INFTY = 1001001001001001001ll;
    vector<int64_t> dist;
    vector<int> prev;
    vector<vector<Pr>> G;
    vector<bool> inQue;
    vector<int> times;

    SPFA(int _N) : N(_N), G(_N), dist(_N, INFTY), prev(_N, -1), inQue(_N), times(_N) {}
    void add_edge(int from, int to, int cst){
        G[from].emplace_back(Pr{cst, to});
    }
    bool solve(int s){
        dist[s] = 0, prev[s] = -1, times[s]++;
        queue<int> que;
        que.push(s);
        inQue[s] = 1, dist[s] = 0;
        while(!que.empty()){
            int u = que.front(); que.pop();
            inQue[u] = 0;
            for(auto v : G[u]){
                if(dist[v.second] > dist[u] + v.first){
                    dist[v.second] = dist[u] + v.first;
                    prev[v.second] = u;
                    if(!inQue[v.second]){
                        if(++times[v.second] >= N) return false;
                        inQue[v.second] = 1;
                        que.push(v.second);
                    }
                }
            }
        }
        return true;
    }
};