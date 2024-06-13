#include<bits/stdc++.h>
using namespace std;

template<class T> struct Healthy2DSegTree{
    function<T(T, T)> Fnc = [](T a, T b){return a + b;};
    T E = 0;
    int size;
    vector<SegTree<T>> st;
    vector<vector<int>> index;
 
    void init(vector<vector<int>> &v) {
        int N = v.size();
        for(size = 1; size < N; size <<= 1);
        index.resize(2 * size);
        for(int i = 0; i < N; i++){
            for(auto &j : v[i]) index[i + size].push_back(j);
        }
        for(int i = size * 2 - 1; i >= 1; i--) {
            sort(index[i].begin(), index[i].end());
            index[i].erase(unique(index[i].begin(), index[i].end()), index[i].end());
            for(auto &j : index[i]) index[i >> 1].push_back(j);
        }
        st.resize(2 * size);
        for(int i = 1; i < size * 2; i++) st[i] = SegTree<T>(index[i].size());
    }
    void update(int x, int y, T v) {
        assert(x < size);
        x += size;
        while (x) {
            int yy = lower_bound(index[x].begin(), index[x].end(), y) - index[x].begin();
            assert(yy != index[x].size());
            assert(y == index[x][yy]);
            st[x].update(yy, v);
            x >>= 1;
        }
    }
    T query(int sx, int tx, int sy, int ty) {
        return query(sx, tx - 1, sy, ty, 1, 0, size);
    }
    T query(int sx, int tx, int sy, int ty, int k, int l, int r) {
        assert(k < size * 2);
        assert(l < r);
        if(r <= sx or tx <= l) return E;
        if(sx <= l and r <= tx) {
            T syy = lower_bound(index[k].begin(), index[k].end(), sy) - index[k].begin();
            T tyy = lower_bound(index[k].begin(), index[k].end(), ty) - index[k].begin();
            return st[k].query(syy, tyy);
        }
        int md = (l + r) / 2;
        T le = query(sx, tx, sy, ty, k * 2, l, md);
        T ri = query(sx, tx, sy, ty, k * 2 + 1, md, r);
        return Fnc(le, ri);
    }
};
