#include<bits/stdc++.h>
using namespace std;

class Dinic{
    using edge = struct{
        ll to, cap, rev;
    };
    int _N;
    vector<vector<edge>> G;
    vector<ll> dist_s, iter;

    void dinic_bfs(int s){
        rep(i, _N) dist_s[i] = NIL;
        queue<int> que;
        dist_s[s] = 0;
        que.push(s);
        while(!que.empty()){
            int v = que.front(); que.pop();
            rep(i, G[v].size()){
                edge &e = G[v][i];
                if(e.cap > 0 && dist_s[e.to] < 0){
                    dist_s[e.to] = dist_s[v] + 1;
                    que.push(e.to);
                }
            }
        }
    }
    int dinic_dfs(int v, int t, int f){
        if(v == t) return f;
        for(int &i = iter[v]; i < (int)G[v].size(); i++){
            edge &e = G[v][i];
            if(e.cap > 0 && dist_s[v] < dist_s[e.to]){
                int d = dinic_dfs(e.to, t, min(f, e.cap));
                if(d > 0){
                    e.cap -= d;
                    G[e.to][e.rev].cap += d;
                    return d;
                }
            }
        }
        return 0;
    }

    public:
    Dinic(int N) : _N(N), G(N), dist_s(N), iter(N) {}
    void add_edge(int from, int to, int cap){
        G[from].emplace_back(edge{to, cap, (ll)G[to].size()});
        G[to].emplace_back(edge{from, 0, (ll)G[from].size() - 1});
    }
    int max_flow(int s, int t){
        int flow = 0;
        while(1){
            dinic_bfs(s);
            if(dist_s[t] < 0) return flow;
            rep(i, _N) iter[i] = 0;
            int f;
            while((f = dinic_dfs(s, t, INF)) > 0)
                flow += f;
        }
    }
};