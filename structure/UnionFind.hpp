#include<bits/stdc++.h>
using namespace std;

template<class T> class UnionFind{
    vector<int> par, rank;
    vector<T> dat;

    void merge(int p, int u){
        dat[p] += dat[u];
    }

    public:
    UnionFind() = default;

    UnionFind(int N) : par(N), rank(N, 0), dat(N, 1) {
        for(int i = 0; i < N; i++) par[i] = i;
    }

    UnionFind(int N, vector<T>& V) : par(N), rank(N, 0), dat(N) {
        for(int i = 0; i < N; i++) par[i] = i;
        for(int i = 0; i < N; i++) dat[i] = V[i];
    }

    void unite(int x, int y){
        x = find(x), y = find(y);
        if(x == y) return;
        if(rank[y] <= rank[x]){
            if(rank[x] == rank[y]) rank[x]++;
            swap(x, y);
        }
        par[x] = y;
        merge(y, x);
    }

    int find(int x){
        if(par[x] == x) return x;
        else{
            dat[x] = dat[par[x] = find(par[x])];
            return par[x];
        }
    }

    const T &operator[](int x){
        return dat[find(x)];
    }

    bool same(int x, int y){
        return find(x) == find(y);
    }
}