// Required Conditions
// x*ex = ex*x = x  in X
// (x1*x2)*x3 = x1*(x2*x3)  in X
// m+em = em+m = m  in M
// (m1+m2)+m3 = m1+(m2+m3)  in M
// x^(m1+m2) = (x^m1)^m2  in X
// (x1*x2)^m = (x1^m)*(x2^m)  in X (note: ABC353G)
template<class X, class M> class LazySegTree{
    vector<X> dat;
    vector<M> lazy;
    int size;

public:
    function<X(X, X)> fx = [&](X x1, X x2){ return x1 + x2; };
    function<void(X&, M)> fxm = [&](X& x, M m){ x = (m.first * x + m.second); };
    function<void(M&, M)> fm = [&](M& m1, M m2){ m1 = make_pair(m2.first * m1.first, m2.first * m1.second + m2.second); };
    function<M(M, int)> fp = [&](M m, int len){ return make_pair(m.first, m.second * len); };
    X ex = 0;
    M em = make_pair(1, 0);

    LazySegTree(int N){
        for(size = 1; size < N; size <<= 1);
        dat.resize((size << 1) - 1, ex);
        lazy.resize((size << 1) - 1, em);
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
    
    void set(int id, X x){
        dat[id + size - 1] = x;
    }

    void build(){
        for(int i = size - 2; i >= 0; i--)
            dat[i] = fx(dat[(i << 1) + 1], dat[(i << 1) + 2]);
    }
};