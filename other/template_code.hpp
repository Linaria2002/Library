#pragma once
#include<bits/stdc++.h>
using namespace std;

// macro
#define rep(i, N) for(ll i = 0; i < (ll)(N); ++i)
#define per(i, N) for(ll i = (ll)(N) - 1; i >= 0; --i)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define bit(n, k) (((n) >> (k)) & 1)
#define pcnt(n) (bitset<64>(n).count())
#define endl '\n'
#define fi first
#define se second
#define mkpr make_pair
#define mktpl make_tuple
#define eb emplace_back

// input/output
template<class T> istream& operator>>(istream& is, vector<T>& V){
    for(auto& it : V) is >> it;
    return is;
}
template<class T> ostream& operator<<(ostream& os, vector<T>& V){
    for(int i = 0; i < (int)V.size(); i++){
        os << V[i];
        os << (i + 1 != (int)V.size() ? " " : "");
    }
    return os;
}

template<class T1, class T2> istream& operator>>(istream& is, pair<T1, T2>& P){
    is >> P.first >> P.second;
    return is;
}
template<class T1, class T2> ostream& operator<<(ostream& os, pair<T1, T2> P){
    os << P.first << " " << P.second << "";
    return os;
}

// setup
void set_fast_ios(size_t precision){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(precision);
    cerr << fixed << setprecision(precision);
}

// make_vector
template <class T>
vector<T> make_vector(size_t a, T b) {
    return vector<T>(a, b);
}
template <class... Ts>
auto make_vector(size_t a, Ts... ts) {
    return vector<decltype(make_vector(ts...))>(a, make_vector(ts...));
}

// debug
#ifdef LOCAL
#define debug(x) cerr << "line"<< __LINE__ << ": " << #x << " = " << x << '\n'
#define debugln() cerr << "line" << __LINE__ << ": passed.\n"
#else
#define debug(x, ...) void(0)
#define debugln() void(0)
#endif

// type
using ll = long long;
using ull = unsigned long long;
using ld = double;
using i128 = __int128_t;
using State = string::iterator;
using Pair = pair<ll, ll>;
using Tuple = tuple<ll, ll, ll>;
template<class T> using max_heap = priority_queue<T>;
template<class T> using min_heap = priority_queue<T, vector<T>, greater<T>>;
template<class T> using vec = vector<T>;
template<class T> using vvec = vec<vec<T>>;
template<class T> using vvvec = vec<vvec<T>>;

// constant
constexpr ll INF = 1001001001;
constexpr ll LINF = 1001001001001001001ll;
constexpr ll MOD998 = 998244353;
constexpr ll MOD107 = (ll)(1e9+7);
constexpr ll NIL = -1;
constexpr ll pm[2] = {1, -1};
constexpr ll dr[4] = {0, 1, 0, -1};
constexpr ll dc[4] = {1, 0, -1, 0};
constexpr ll dr8[8] = {0, 1, 1, 1, 0, -1, -1, -1};
constexpr ll dc8[8] = {1, 1, 0, -1, -1, -1, 0, 1};

// Gcd, Lcm
ll Gcd(ll a, ll b){ return b ? Gcd(b, a % b) : abs(a);}
ll Lcm(ll a, ll b){ return a / Gcd(a, b) * b;}

// pow
template<class T> T powi(T x, ll exp){
    return exp > 0 ? (exp & 1 ? x : 1) * powi(x * x, exp >> 1) : x / x;
}
ll modpow(ll x, ll exp, ll mod){
    x %= mod;
    return exp > 0 ? (exp & 1 ? x : 1) * modpow(x * x, exp >> 1, mod) % mod : 1;
}

ll Ceil(ll a, ll b){
    return (a + b - 1) / b;
}

// chmin/max
template<class T> bool chmin(T &a, T b){ return a > b ? (a = b, true) : 0;}
template<class T> bool chmax(T &a, T b){ return a < b ? (a = b, true) : 0;}

#include "atcoder/modint.hpp"
