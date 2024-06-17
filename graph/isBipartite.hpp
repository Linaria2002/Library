// Only for a connected graph
bool isbip(vector<vector<int>> &G){
    int N = G.size();
    vector<int> C(N, -1);
    C[0] = 0;
    queue<int> que;
    que.push(0);
    while(!que.empty()){
        int u = que.front();
        que.pop();
        for(auto v : G[u]){
            if(C[u] == C[v]) return false;
            if(C[v] == -1){
                C[v] = !C[u];
                que.push(v);
            }
        }
    }
    return true;
}