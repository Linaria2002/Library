#include<bits/stdc++.h>
using namespace std;

class xorshift{
    uint64_t state = time(nullptr);
    public:
    xorshift(){
        for(int i = 0; i < 100; i++) gen();
    }
    uint64_t gen(){
        uint64_t res = state;
        res ^= res << 13;
        res ^= res >> 7;
        res ^= res << 17;
        return state = res;
    }
    uint64_t get_val(uint64_t L, uint64_t R){
        return gen() % (R - L + 1) + L;
    }
};