class Ford_Fulkerson{
public:
    typedef pair<int, pair<ll, int>> to_cap_rev;

    vector<vector<to_cap_rev>> G;
    vector<bool> used;
    int Vsize = 100;
    bool NIL_unpush = true;

    void init(int n){
        Vsize = n;
        G.resize(Vsize);
        used.resize(Vsize);
    }

    void link(int from, int to, ll cap){
        G[from].push_back(make_pair(to, make_pair(cap, G[to].size())));
        G[to].push_back(make_pair(from, make_pair(0, G[from].size() - 1)));
    }

    ll dfs(int v, int t, ll flow){
        if(v == t) return flow;
        used[v] = true;
        for(int i = 0; i < G[v].size(); i++){
            int to = G[v][i].first, rev = G[v][i].second.second;
            ll cap = G[v][i].second.first;

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

    ll solve(int s, int t){
        ll flow = 0;
        while(1){
            for(int i = 0; i < Vsize; i++) used[i] = false;
            ll f = dfs(s, t, INF);
            if(f == 0) break;
            flow += f;
        }
        return flow;
    }
};