class LCA{
public:
    vector<vector<int>> tree;
    int root, n, logv;
    vector<vector<int>> parent; // k, 2^k
    vector<int> depth;

    LCA(int N, int R, vector<vector<int>> &G) : root(R), tree(G) {
        for(logv = 0, n = 1; n <= N; n <<= 1, ++logv);

        parent.resize(logv, vector<int>(N));
        depth.resize(N);
        dfs(root, NIL, 0);

        rep(i, logv - 1)rep(j, N){
            if(parent[i][j] < 0) parent[i + 1][j] = NIL;
            else parent[i+1][j] = parent[i][parent[i][j]];
        }
    }
    void dfs(int v, int p, int d){
        parent[0][v] = p;
        depth[v] = d;
        rep(i, tree[v].size()){
            if(tree[v][i] != p) dfs(tree[v][i], v, d + 1);
        }
    }
    int query(int u, int v){
        if(depth[u] > depth[v]) swap(u, v);
        rep(i, logv){
            if(((depth[v] - depth[u]) >> i) & 1) v = parent[i][v];
        }
        if(u == v) return u;
        per(i, logv){
            if(parent[i][u] != parent[i][v]){
                u = parent[i][u];
                v = parent[i][v];
            }
        }
        return parent[0][u];
    }
};

