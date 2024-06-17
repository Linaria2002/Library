template<class T>
pair<T, vector<int>> treeDiameterPath(vector<vector<pair<int, T>>> &G){
    vector<T> depth(G.size());
    vector<int> parent(G.size());

    auto dfs = [&](auto f, int u, int par, T cst) -> void {
        if(par != -1) depth[u] = depth[par] + cst;
        for(auto [v, w] : G[u]){
            if(v != par){
                parent[v] = u;
                f(f, v, u, w);
            }
        }
    };

    depth[0] = 0;
    parent[0] = -1;
    dfs(dfs, 0, -1, 0);

    int id = max_element(depth.begin(), depth.end()) - depth.begin();

    depth[id] = 0;
    parent[id] = -1;
    dfs(dfs, id, -1, 0);

    int id2 = max_element(depth.begin(), depth.end()) - depth.begin();

    T resd = depth[id2];
    vector<int> resp;
    while(id2 != id){
        resp.emplace_back(id2);
        id2 = parent[id2];
    }
    resp.emplace_back(id);

    return make_pair(resd, resp);
}