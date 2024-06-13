// ※テンプレート依存
// ※not verified
#include<bits/stdc++.h>
using namespace std;

class mint{
    public:
    ll x;
    constexpr mint(ll _x) : x((_x%MOD+MOD)%MOD) {}

    constexpr const mint inv() const {
        mint res(MOD);
        for(ll exp = MOD-2; exp; exp >>= 1){
            if(exp & 1) res *= *this;
        }
        return res;
    }
    constexpr mint operator-() const {
        return mint(-x);
    }
    constexpr mint& operator+=(const mint& a) {
        if ((x += a.x) >= MOD) x -= MOD;
        return *this;
    }
    constexpr mint& operator-=(const mint& a) {
        if ((x += MOD-a.x) >= MOD) x -= MOD;
        return *this;
    }
    constexpr mint& operator*=(const  mint& a) {
        (x *= a.x) %= MOD;  
        return *this;
    }
    constexpr mint& operator/=(const mint& a) {
        return (*this) *= a.inv();
    }
    constexpr mint operator+(const mint& a) const{
        mint res(*this);
        return res+=a;
    }
    constexpr mint operator-(const mint& a) const {
        mint res(*this);
        return res-=a;
    }
    constexpr mint operator*(const mint& a) const {
        mint res(*this);
        return res*=a;
    }
    constexpr mint operator/(const mint& a) const {
        mint res(*this);
        return res/=a;
    }
    friend istream& operator>>(istream& is, mint& m){
        is >> m.x;
        return is;
    }
    friend ostream& operator<<(ostream& os, const mint& m){
        os << m.x;
        return os;
    }
};