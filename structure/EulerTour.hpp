struct EulerTour{
    vector<int> in, out, depth;
    vector<int> visit; // the order of visited vertex

    EulerTour(vector<vector<int>>& G, int root)
    : in(G.size()), out(G.size()), depth(G.size()), visit(G.size() * 2){
        int cnt = 0;
        auto dfs = [&](auto f, int u, int par, int d) -> void {
            visit[cnt] = u;
            depth[u] = d;
            in[u] = cnt; cnt++;
            for(auto v : G[u]){
                if(v != par) f(f, v, u, d + 1);
            }
            visit[cnt] = par;
            out[u] = cnt; cnt++;
        };
        dfs(dfs, root, -1, 0);
    }

    // for the use of find lca(u, v) (segtree or sparsetable required)
    // size: G.size() * 2
    // element: (depth of the vertex, visiting vertex)
    // fnc: return min(a, b);
    // lca(u, v) is query(treeRange(u, v).first, treeRange(u, v).second);
    pair<int, int> treeRange(int u, int v){ 
        return make_pair(min(in[u], in[v]), max(out[u], out[v]));
    }

    // return corresponding range [first, second)
    pair<int, int> vertexAt(int u){ return make_pair(in[u], out[u]); };
    
    // return corresponding range [first, second)
    pair<int, int> edgeAt(int u, int v){
        if(in[u] > in[v]) swap(u, v);
        return make_pair(in[v], out[v]);
    }
};