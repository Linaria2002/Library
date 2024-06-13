#include<bits/stdc++.h>
using namespace std;

template<class T> vector<T> fast_zeta(int N, vector<T> &A){
    vector<T> dp(1 << N);
    for(int i = 0; i < (1 << N); i++){
        dp[i] = A[i];
    }
    for(int j = 0; j < N; j++){
        for(int i = 0; i < (1 << N); i++){
            if(i & (1 << j)){
                dp[i] += dp[i & ~(1 << j)];
            }
        }
    }
    return dp;
}