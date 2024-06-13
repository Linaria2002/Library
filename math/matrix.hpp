#include<bits/stdc++.h>
using namespace std;

template<class T>
struct Matrix{
    T one = (1ll << 32) - 1;
    T zero = 0;
    function<T(const T&, const T&)> add = [](const T& a, const T& b){ return a ^ b; };
    function<T(const T&, const T&)> mul = [](const T& a, const T& b){ return a & b; };
    int R, C;
    vector<vector<T>> dat;

    Matrix(int r, int c) : R(r), C(c), dat(r, vector<T>(c, zero)) {}

    inline vector<T> &operator[](int k){ return (dat.at(k)); }
    
    constexpr Matrix operator*(const Matrix& A) const {
        int L = (int)this->R, M = (int)A.R, N = (int)A.C;
        assert((int)this->C == M);
        Matrix res(L, N);
        for(int i = 0; i < L; i++){
            for(int j = 0; j < N; j++){
                for(int k = 0; k < M; k++){
                    res[i][j] = add(res[i][j], mul(this->dat[i][k], A.dat[k][j]));
                }
            }
        }
        return res;
    }

    Matrix pow(const Matrix& A, long long exp){
        int N = A.R;
        assert(N == A.C);
        Matrix res(N, N), X = A;
        for(int i = 0; i < N; i++) res[i][i] = one;
        for(; exp > 0; exp >>= 1){
            if(exp & 1) res = res * X;
            X = X * X;
        }
        return res;
    }
};