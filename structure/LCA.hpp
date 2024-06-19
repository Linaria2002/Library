class LCA{
public:
    int root, n, logv;
    vector<vector<int>> tree;
    vector<vector<int>> parent; // k, 2^k
    vector<int> depth;

    LCA(int N, int R, vector<vector<int>> &G) : root(R), tree(G) {
        for(logv = 0, n = 1; n <= N; n <<= 1, ++logv);

        parent.resize(logv, vector<int>(N));
        depth.resize(N);
        dfs(root, -1, 0);

        for(int i = 0; i < logv - 1; i++)for(int j = 0; j < N; j++){
            if(parent[i][j] < 0) parent[i + 1][j] = -1;
            else parent[i+1][j] = parent[i][parent[i][j]];
        }
    }
    void dfs(int v, int p, int d){
        parent[0][v] = p;
        depth[v] = d;
        for(int i = 0; i < (int)tree[v].size(); i++){
            if(tree[v][i] != p) dfs(tree[v][i], v, d + 1);
        }
    }
    int query(int u, int v){
        if(depth[u] > depth[v]) swap(u, v);
        for(int i = 0; i < logv; i++){
            if(((depth[v] - depth[u]) >> i) & 1) v = parent[i][v];
        }
        if(u == v) return u;
        for(int i = logv; i >= 0; i--){
            if(parent[i][u] != parent[i][v]){
                u = parent[i][u];
                v = parent[i][v];
            }
        }
        return parent[0][u];
    }
};