#include<bits/stdc++.h>
using namespace std;

class SCC{
    int N;
    vector<vector<int>> G;
    vector<vector<int>> inv;
    vector<int> vs;
    vector<bool> used;
    void dfs(int u){
        used[u] = true;
        for(auto v : G[u]){
            if(!used[v]) dfs(v);
        }
        vs.emplace_back(u);
    }
    void rdfs(int u, int k){
        used[u] = true;
        cmp[u] = k;
        for(auto v : inv[u]){
            if(!used[v]) rdfs(v, k);
        }
    }

    public:
    vector<int> cmp;
    SCC(int _N) : N(_N), G(_N), inv(_N), used(_N, 0), cmp(_N) {}
    
    void add_edge(int u, int v){
        G[u].emplace_back(v);
        inv[v].emplace_back(u);
    }
    int scc(){
        for(int i = 0; i < N; i++) used[i] = false;
        vs.clear();
        for(int u = 0; u < N; u++){
            if(!used[u]) dfs(u);
        }
        for(int i = 0; i < N; i++) used[i] = false;
        int k = 0;
        for(int i = vs.size() - 1; i >= 0; i--){
            if(!used[vs[i]]) rdfs(vs[i], k++);
        }
        return k;
    }
};