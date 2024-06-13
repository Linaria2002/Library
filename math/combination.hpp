#include<bits/stdc++.h>
using namespace std;

const int MOD = 998244353;
class Combination{
    int max_val; // (2^n)-2
    vector<long long> fact_, invf_;

    void build(int n){
        assert(n < MOD);
        int prev_val = max_val;
        while(max_val < n) max_val = (max_val << 1) | 2;
        max_val = min(max_val, n);
        fact_.resize(max_val + 1);
        invf_.resize(max_val + 1);
        for(int i = prev_val + 1; i <= max_val; i++){
            fact_[i] = fact_[i-1] * i % MOD;
        }
        invf_[max_val] = 1;
        for(long long x = fact_[max_val], k = MOD-2; k > 0; k >>= 1){
            if(k & 1) invf_[max_val] = invf_[max_val] * x % MOD;
            x = x * x % MOD;
        }
        for(int i = max_val; i > prev_val + 1; i--){
            invf_[i-1] = invf_[i] * i % MOD;
        }
    }
    bool check(int n){
        if(n < 0) return false;
        if(n > max_val) build(n);
        return true;
    }
    bool check(int n, int r){
        if(n < r || r < 0) return false;
        if(n > max_val) build(n);
        return true;
    }

    public:
    Combination() : max_val(0), fact_(1, 1), invf_(1, 1) {}
    Combination(int N) : max_val(0), fact_(1, 1), invf_(1, 1) {build(N);}
    long long fact(int n){
        if(!check(n)) return 0;
        return fact_[n];
    }
    long long invf(int n){
        if(!check(n)) return 0;
        return invf_[n];
    }
    long long nPr(int n, int r){
        if(!check(n, r)) return 0;
        return fact_[n] * invf_[n-r] % MOD;
    }
    long long nCr(int n, int r){
        if(!check(n, r)) return 0;
        return fact_[n] * invf_[n-r] % MOD * invf_[r] % MOD;
    }
};
