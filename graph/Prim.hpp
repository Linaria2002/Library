#include<bits/stdc++.h>
using namespace std;

class Prim{
    int size;
    vvec<pair<ll, int>> G;
    vec<ll> dist;
    vec<int> prev;

    public:
    Prim(int N) : size(N), G(N), dist(N, LINF), prev(N, NIL) {}
    void add_edge(int from, int to, ll cst){
        G[from].eb(mkpr(cst, to));
    }
    ll solve(int R){
        min_heap<tuple<ll, int, int>> heap;
        dist[R] = 0, prev[R] = R;
        for(auto it : G[R]){
            heap.push(mktpl(it.fi, R, it.se));
        }

        ll res = 0;
        int num = 1;
        if(size == 1) return 0;

        while(!heap.empty()){
            tuple<ll, int, int> T = heap.top();
            heap.pop();
            int u = get<1>(T);
            int v = get<2>(T);
            if(prev[v] != NIL) continue;

            prev[v] = u;
            dist[v] = dist[u] + get<0>(T);
            num++;
            res += get<0>(T);

            if(num == size) return res;

            for(auto it : G[v]){
                heap.push(mktpl(it.fi, v, it.se));
            }
        }
        return NIL;
    }
};