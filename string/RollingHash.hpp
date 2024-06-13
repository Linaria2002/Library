#include<bits/stdc++.h>
using namespace std;

class RollingHash{
    public:
    static const uint64_t MASK30 = (1ull << 30) - 1;
    static const uint64_t MASK31 = (1ull << 31) - 1;
    static const uint64_t _MOD = (1ull << 61) - 1;
    static const uint64_t MASK61 = _MOD;
    static const uint64_t POSITIVIZER = _MOD * 4;
    const uint64_t base;
    vector<uint64_t> power;

    static uint64_t generateBase(){
        mt19937_64 mt(chrono::steady_clock::now().time_since_epoch().count());
        uniform_int_distribution< uint64_t > rand(1ull << 32, RollingHash::_MOD - 1);
        return rand(mt);
    }
    uint64_t Mul(uint64_t a, uint64_t b){
        uint64_t au = a >> 31, ad = a & MASK31, bu = b >> 31, bd = b & MASK31;
        uint64_t mid = ad * bu + au * bd;
        uint64_t midu = mid >> 30, midd = mid & MASK30;
        return CalcMod(au * bu * 2 + midu + (midd << 31) + ad * bd);
    }
    uint64_t CalcMod(uint64_t x){
        uint64_t xu = x >> 61, xd = x & MASK61;
        uint64_t res = xu + xd;
        if(res >= _MOD) res -= _MOD;
        return res;
    }
    void expand(int sz){
        if(power.size() < sz + 1){
            int pre_sz = power.size();
            power.resize(sz + 1);
            for(int i = pre_sz - 1; i < sz; i++){
                power[i + 1] = Mul(power[i], base);
            }
        }
    }

    RollingHash(uint64_t base = generateBase()) : base(base), power(1, 1) {}
    vector<uint64_t> buildTable(const string &str){
        int sz = str.size();
        vector<uint64_t> hashed(sz + 1);
        for(int i = 0; i < sz; i++){
            hashed[i + 1] = CalcMod(Mul(hashed[i], base) + str[i]);
        }
        return hashed;
    }
    template<class T> vector<uint64_t> buildTable(const vector<T> &V){
        int sz = V.size();
        vector<uint64_t> hashed(sz + 1);
        for(int i = 0; i < sz; i++){
            hashed[i + 1] = CalcMod(Mul(hashed[i], base) + V[i]);
        }
        return hashed;
    }
    uint64_t getHash(const vector<uint64_t> &H, int l, int r){
        expand(r - l);
        return  CalcMod(H[r] + POSITIVIZER - Mul(H[l], power[r - l]));
    }
    int lcp(const vector<uint64_t> &H1, int l1, int r1, const vector<uint64_t> &H2, int l2, int r2){
        int len = min(r1 - l1, r2 - l2);
        int ok = 0, ng = len + 1;
        while(ok < ng - 1){
            int mid = (ok + ng) / 2;
            if(getHash(H1, l1, l1 + mid) == getHash(H2, l2, l2 + mid)) ok = mid;
            else ng = mid;
        }
        return ok;
    }
};