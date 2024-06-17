template<class T>
class SegTree{
    public:
    function<T(T&, T&)> Fnc;
    function<void(T&, T&)> Upd;
    vector<T> dat;
    T E = 0;
    int size;

    public:
    
    SegTree(int N) : Fnc([](T& a, T& b){return a + b;}), Upd([](T& a, T& b){a += b;}), E(0){
        for(size = 1; size < N; size <<= 1);
        dat.resize((size << 1) - 1, E);
    }

    SegTree(int N, function<T(T&, T&)> f, function<void(T&, T&)> g, T e)
    : Fnc(f), Upd(g), E(e){
        for(size = 1; size < N; size <<= 1);
        dat.resize((size << 1) - 1, E);
    }

    void set(int idx, T x){ Upd(dat[idx + size - 1], x); }
    void build(){
        for(int i = size - 2; i >= 0; i--)
            dat[i] = Fnc(dat[(i << 1) + 1], dat[(i << 1) + 2]);
    }

    void update(int idx, T x){
        idx += size - 1;
        Upd(dat[idx], x);
        while(idx > 0){
            idx = (idx - 1) >> 1;
            dat[idx] = Fnc(dat[(idx << 1) + 1], dat[(idx << 1) + 2]);
        }
    }
    T query(int l, int r){ return query(l, r, 0, 0, size); }
    T query(int qL, int qR, int k, int l, int r){
        if(r <= qL || qR <= l) return E;
        if(qL <= l && r <= qR) return dat[k];
        T vl = query(qL, qR, (k << 1) + 1, l, (l + r) >> 1);
        T vr = query(qL, qR, (k << 1) + 2, (l + r) >> 1, r);
        return Fnc(vl, vr);
    }
};
