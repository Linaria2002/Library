#include<bits/stdc++.h>
using namespace std;

ll ExtGcd(ll a, ll b, ll &x, ll &y){
    ll d = a;
    if(b != 0){
        d = ExtGcd(b, a % b, y, x);
        y -= (a / b) * x;
    }
    else{
        x = 1, y = 0;
    }
    return d;
}

pair<ll, ll> ChineseRem(vec<ll> &b, vec<ll> &m) {
    ll r = 0, M = 1;
    for (int i = 0; i < (int)b.size(); ++i) {
        ll p, q;
        ll d = ExtGcd(M, m[i], p, q); // p is inv of M/d (mod. m[i]/d)
        if ((b[i] - r) % d != 0) return make_pair(0, -1);
        ll tmp = (b[i] - r) / d * p % (m[i]/d);
        r += M * tmp;
        M *= m[i]/d;
    }
    return mkpr((r % M + M) % M, M);
}
