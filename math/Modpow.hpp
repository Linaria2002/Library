// ※テンプレート依存
#include<bits/stdc++.h>
using namespace std;

ll modpow(ll x, ll exp, ll mod){
    ll res = 1;
    for(x %= mod; exp > 0; exp >>= 1){
        if(exp & 1) res = res * x % mod;
        x = x * x % mod;
    }
    return res;
}