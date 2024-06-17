template<class T>
struct SetSegTree : public SegTree<T> {
    using SegTree<T>::SegTree;
    using SegTree<T>::Fnc;
    using SegTree<T>::Upd;
    using SegTree<T>::E;
    using SegTree<T>::dat;
    using SegTree<T>::size;
    function<bool(T, T)> Cmp;

    SetSegTree(int N) : SegTree<T>::SegTree(N), Cmp([](T a, T b){ return a < b; }){}

    SetSegTree(int N, function<T(T&, T&)> f, function<void(T&, T&)> g, T e, function<bool(T, T)> c)
    : SegTree<T>::SegTree(N, f, g, e), Cmp(c){}
        
    int left_lower(int l, int r, T x){
        T y = E;
        int res = lower_bound(l, r, x, y, 0, 0, size, true);
        return l <= res && res < r ? res : -1;
    }

    int right_lower(int l, int r, T x){
        T y = E;
        int res = lower_bound(l, r, x, y, 0, -1, size - 1, false);
        return l < res && res <= r ? res : -1;
    }

    int lower_bound(int qL, int qR, T x, T& y, int k, int l, int r, bool isLeft){
        if(r <= qL || qR <= l) return -2;
        if(qL <= l && r <= qR){
            if(Cmp(Fnc(dat[k], y), x)){
                Upd(y, dat[k]);
                return isLeft ? r : l;
            }
        }
        if(k >= size - 1) return (k - (size - 1));
        if(isLeft){
            int idl = lower_bound(qL, qR, x, y, (k << 1) + 1, l, (l + r) >> 1, isLeft);
            if(idl != (l + r) >> 1 && idl != -2) return idl;
            return lower_bound(qL, qR, x, y, (k << 1) + 2, (l + r) >> 1, r, isLeft);
        }
        else{
            int idr = lower_bound(qL, qR, x, y, (k << 1) + 2, (l + r) >> 1, r, isLeft);
            if(idr != (l + r) >> 1 && idr != -2) return idr;
            return lower_bound(qL, qR, x, y, (k << 1) + 1, l, (l + r) >> 1, isLeft);
        }
    }
}; 