#pragma once

template<class T> T modpow(T x, T exp, T mod){
    T res = 1;
    for(x %= mod; exp > 0; exp >>= 1){
        if(exp & 1) res = res * x % mod;
        x = x * x % mod;
    }
    return res;
}