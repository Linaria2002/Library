#include<bits/stdc++.h>
using namespace std;

class Warshall_Floyd{
    vector<vector<ll>> dist;
    int size;

    public:
    Warshall_Floyd(int N) : size(N), dist(N, vector<ll>(N, INF)){
        for(int i = 0; i < N; i++) dist[i][i] = 0;
    }
    void add_edge(int u, int v, int w){
        dist[u][v] = w;
    }
    bool solve(){
        for(int k = 0; k < size; k++){
            for(int i = 0; i < size; i++){
                for(int j = 0; j < size; j++){
                    if(dist[i][k] == INF || dist[k][j] == INF) continue;
                    chmin(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
        for(int i = 0; i < size; i++)
            if(dist[i][i] < 0) return false;
        return true;
    }
    int find_dist(int u, int v){
        return dist[u][v];
    }
    bool need_edge(int u, int v, int w){
        for(int i = 0; i < size; i++){
            if(i == u || i == v) continue;
            if(w >= dist[u][i] + dist[i][v]) return false;
        }
        return true;
    }
};