class BellmanFord{
    public:
    int N;
    const int64_t INFTY = 1001001001001001001ll;
    vector<vector<pair<int, int64_t>>> G;
    vector<int64_t> dist;

    BellmanFord(int N_) : N(N_), G(N), dist(N_, INFTY) {}
    void add_edge(int u, int v, int64_t w){
        G[u].emplace_back(make_pair(v, w));
    }
    bool solve(int s){
        dist[s] = 0;
        int T = N;
        bool update;
        while(T--){
            update = false;
            for(int u = 0; u < N; u++){
                for(auto v : G[u]){
                    if(dist[v.first] > dist[u] + v.second && dist[u] != INFTY){
                        update = true;
                        dist[v.first] = dist[u] + v.second;
                    }
                }
            }
            if(!update) break;
        }
        return !update;
    }
};