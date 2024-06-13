#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> gridBfs(const vector<vector<char>>& G, int r0, int c0){
    static const int _dr[4] = {0, 1, 0, -1}, _dc[4] = {1, 0, -1, 0};
    int H = G.size(), W = G[0].size();
    vector<vector<int>> dist(H, vector<int>(W, 1e9+10));

    using T = struct{ int r, c; };
    dist[r0][c0] = 0;
    queue<T> que;
    que.push(T{r0, c0});

    while(!que.empty()){
        T u = que.front();
        que.pop();

        for(int i = 0; i < 4; i++){
            int nr = u.r + _dr[i], nc = u.c + _dc[i];
            if(nr < 0 || H <= nr || nc < 0 || W <= nc) continue;
            if(G[nr][nc] == '#') continue;

            if(dist[nr][nc] > dist[u.r][u.c] + 1){
                dist[nr][nc] = dist[u.r][u.c] + 1;
                que.push(T{nr, nc});
            }
        }
    }

    return dist;
}
