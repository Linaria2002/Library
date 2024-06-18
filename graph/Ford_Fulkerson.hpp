class Ford_Fulkerson{
public:
    typedef pair<int, pair<long long, int>> to_cap_rev;

    const int FF_INF = 1001001001;
    vector<vector<to_cap_rev>> G;
    vector<bool> used;
    int Vsize = 100;
    bool NIL_unpush = true;

    void init(int n){
        Vsize = n;
        G.resize(Vsize);
        used.resize(Vsize);
    }

    void link(int from, int to, long long cap){
        G[from].push_back(make_pair(to, make_pair(cap, G[to].size())));
        G[to].push_back(make_pair(from, make_pair(0, G[from].size() - 1)));
    }

    long long dfs(int v, int t, long long flow){
        if(v == t) return flow;
        used[v] = true;
        for(int i = 0; i < (int)G[v].size(); i++){
            int to = G[v][i].first, rev = G[v][i].second.second;
            long long cap = G[v][i].second.first;

            if(!used[to] && cap > 0){
                int res = dfs(to, t, min(cap, flow));
                if(res > 0){
                    G[v][i].second.first -= res; 
                    G[to][rev].second.first += res;
                    return res;
                }
            }
        }
        return 0;
    }

    long long solve(int s, int t){
        long long flow = 0;
        while(1){
            for(int i = 0; i < Vsize; i++) used[i] = false;
            long long f = dfs(s, t, FF_INF);
            if(f == 0) break;
            flow += f;
        }
        return flow;
    }
};