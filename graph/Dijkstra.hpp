#include<bits/stdc++.h>
using namespace std;

template<class T> struct Dijkstra{
    using DS = pair<T, int>;
    int N;
    T INFTY = 1001001001001001001ll;
    vector<T> dist;
    vector<int> prev;
    priority_queue<DS, vector<DS>, greater<DS>> Que;
    vector<vector<DS>> G;

    Dijkstra(int N) : N(N), G(N), dist(N), prev(N) {}
    void add_edge(int from, int to, T cst){
        G[from].emplace_back(DS{cst, to});
    }
    void solve(int s){
        for(int i = 0; i < N; i++) dist[i] = INFTY, prev[i] = -1;
        dist[s] = 0, prev[s] = -1;
        Que.push(DS{0, s});
        while(!Que.empty()){
            DS p = Que.top();
            Que.pop();
            int u = p.second;
            if(dist[u] != p.first) continue;
            for(auto v : G[u]){
                if(dist[v.second] > dist[u] + v.first){
                    dist[v.second] = dist[u] + v.first;
                    prev[v.second] = u;
                    Que.push(DS{dist[v.second], v.second});
                }
            }
        }
    }
};
