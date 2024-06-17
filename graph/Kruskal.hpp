//G = (cost, to), create := construct a graph
template<class T> T kruskal(vector<vector<pair<T, int>>> &G, bool create = false){
    using KrTpl = tuple<T, int, int, int>; 
    int N = G.size(), merged = 0;
    vector<KrTpl> edges;
    UnionFind UF(N);
    vector<bool> used;
 
    for(int i = 0; i < N; i++){
        for(auto [cst, v] : G[i]){
            if(i > v) continue;
            edges.eb(make_tuple(cst, i, v, used.size()));
            edges.eb(make_tuple(cst, v, i, used.size()));
            used.emplace_back(0);
        }
        if(create) G[i].clear();
    }
    sort(edges.begin(), edges.end(), [](const KrTpl &a, const KrTpl &b){
        return get<0>(a) < get<0>(b);
    });
 
    T res = 0;
    int E = edges.size();
 
    for(int i = 0; i < E; i++){
        auto [c, u, v, b] =  edges[i];
        if(used[b]) continue;
        if(u > v) swap(u, v);

        if(!UF.same(u, v) || c < 0){
            used[b] = 1;
            if(!UF.same(u, v)){
                merged++;
                UF.unite(u, v);
            }
            res += c;
            if(merged == N - 1 && c >= 0) return res;
            if(create){
                G[u].emplace_back(make_pair(c, v));
                G[v].emplace_back(make_pair(c, u));
            }
        }
    }
    return (merged == N - 1) ? res : 2e18;
}