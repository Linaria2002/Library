#pragma once
#include "RollingHash.hpp"
#include "../structure/SegTree.hpp"

class DynamicRollingHash : RollingHash{
    using RollingHash::RollingHash;
    using Pr = pair<unsigned long long, int>;

    public:
    template<class T> SegTree<Pr> build(const vector<T> &V){
        int sz = V.size();
        expand(sz + 10);
        SegTree<Pr> ST(sz,
            [&](Pr& a, Pr& b){ return Pr(Add(Mul(a.first, power[b.second]), b.first), a.second + b.second);},
            [&](Pr& a, Pr& b){ a = b; },
            Pr(0, 0)
        );
        for(int i = 0; i < sz; i++){
            ST.set(i, Pr(V[i], 1));
        }
        ST.build();
        return ST;
    }

    void update(SegTree<Pr>& Hash, int idx, int c){
        Hash.update(idx, Pr(c, 1));
    }

    unsigned long long query(SegTree<Pr>& Hash, int l, int r){
        return Hash.query(l, r).first;
    }
};