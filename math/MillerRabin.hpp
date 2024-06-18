#pragma once
#include "modpow.hpp"

bool MillerRabin(__int128_t n){
    const int K = 7;
    static const __int128_t mod[7] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022};
    if(n == 2) return true;
    if(n == 1 || (n & 1) == 0) return false;
    __int128_t d((n - 1) >> 1);
    while((d & 1) == 0) d >>= 1;
    for(int i = 0; i < K; i++){
        __int128_t a(mod[i]);
        if(a >= n) break;
        __int128_t t(d);
        __int128_t y(modpow(a, t, n));
        //cerr << a << " " << t << " " << y << "\n";
        while(t != n - 1 && y != 1 && y != n - 1){
            //if(n == 13) cerr << a << " " << t << " " << y << "\n";
            y = y % n * y % n;
            t <<= 1;
        }
        if(y != n - 1 && (t & 1) == 0) return false;
    }
    return true;
}