#include<bits/stdc++.h>
using namespace std;

template<class T>
class SparseTable{
    vector<vector<T>> dat;
    vector<int> lookup;
    function<T(T, T)> Fnc = [](T a, T b){ return min(a, b); };

    public:
    SparseTable(const vector<T> &V){
        int b = 0;
        while((1 << b) <= V.size()) b++;
        dat.resize(b, vector<T>(1 << b));
        for(int i = 0; i < (int)V.size(); i++){
            dat[0][i] = V[i];
        }
        for(int i = 1; i < b; i++){
            for(int j = 0; j + (1 << i) <= (1 << b); j++){
                dat[i][j] = Fnc(dat[i - 1][j], dat[i - 1][j + (1 << (i - 1))]);
            }
        }
        lookup.resize(V.size() + 1);
        for(int i = 2; i < (int)lookup.size(); i++){
            lookup[i] = lookup[i >> 1] + 1;
        }
    }
    T query(int l, int r){
        int b = lookup[r - l];
        return Fnc(dat[b][l], dat[b][r - (1 << b)]);
    }
};