#include<bits/stdc++.h>
using namespace std;

template<class T> struct rand_generator{
    mt19937_64 mt;
    uniform_int_distribution<uint64_t> rnd;
    rand_generator(uint64_t L = 0, uint64_t R = UINT64_MAX){
        mt = mt19937_64(chrono::steady_clock::now().time_since_epoch().count());
        rnd = uniform_int_distribution<uint64_t>(L, R);
    }
    uint64_t gen(){ return rnd(mt); }
    T gen(T L, T R){ return rnd(mt) % (R - L + 1) + L; }
};