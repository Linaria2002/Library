#include<bits/stdc++.h>
using namespace std;

template<class X, class M>
class LazyTree{
    function<X(X, X)> fx = [](X x1, X x2){ return x1 + x2; };
    function<void(X&, M)> fxm = [](X& x, M m){ x += m; };
    function<void(M&, M)> fm = [](M& m1, M m2){ m1 += m2; };
    function<M(M, int)> fp = [](M m, int n){ return m * n; };
    X ex = 0;
    M em = 0;
    vector<X> dat;
    vector<M> lazy;
    int size;
    public:
    LazyTree(int N){
        for(size = 1; size < N; size <<= 1);
        dat.resize((size << 1) - 1, ex);
        lazy.resize((size << 1) - 1, em);
    }
    LazyTree(vector<X> &V){
        int N = V.size();
        for(size = 1; size < N; size <<= 1);
        dat.resize((size << 1) - 1, ex);
        lazy.resize((size << 1) - 1, em);
        for(int i = 0; i < N; i++) dat[i + size - 1] = V[i];
        for(int i = size - 2; i >= 0; i--)
            dat[i] = fx(dat[(i << 1) + 1], dat[(i << 1) + 2]);
    }
    void eval(int k, int len){
        if(lazy[k] == em) return;
        if(k < size - 1){
            fm(lazy[(k << 1) + 1], lazy[k]);
            fm(lazy[(k << 1) + 2], lazy[k]);
        }
        fxm(dat[k], fp(lazy[k], len));
        lazy[k] = em;
    }
    void update(int l, int r, M m){ return update(l, r, m, 0, 0, size); }
    void update(int qL, int qR, M m, int k, int l, int r){
        eval(k, r - l);
        if(qL <= l && r <= qR){
            fm(lazy[k], m);
            eval(k, r - l);
        }
        else if(qL < r && l < qR){
            update(qL, qR, m, (k << 1) + 1, l, (l + r) >> 1);
            update(qL, qR, m, (k << 1) + 2, (l + r) >> 1, r);
            dat[k] = fx(dat[(k << 1) + 1], dat[(k << 1) + 2]);
        }
    }
    X query(int l, int r){ return query(l, r, 0, 0, size); }
    X query(int qL, int qR, int k, int l, int r){
        eval(k, r - l);
        if(r <= qL || qR <= l) return ex;
        if(qL <= l && r <= qR) return dat[k];
        X vl = query(qL, qR, (k << 1) + 1, l, (l + r) >> 1);
        X vr = query(qL, qR, (k << 1) + 2, (l + r) >> 1, r);
        return fx(vl, vr);
    }
};