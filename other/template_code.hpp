#include<bits/stdc++.h>
#define int ll
#define rep(i, N) for(int i = 0; i < (int)(N); ++i)
#define rep1(i, N) for(int i = 1; i <= (int)(N); ++i)
#define per(i, N) for(int i = (int)(N)-1; i >= 0; --i)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define bit(n, k) (((n) >> (k)) & 1)
#define pcnt(n) (bitset<64>(n).count())
#define YesNo(ans) (ans) ? cout << "Yes\n" : cout << "No\n"
#define endl '\n'
#define fi first
#define se second
#define mkpr make_pair
#define mktpl make_tuple
#define eb emplace_back

using namespace std;
using ll = int64_t;
using ull = uint64_t;
using ld = long double;
using point = struct{ ld x, y; };
using State = string::iterator;
template<class T> using max_heap = priority_queue<T>;
template<class T> using min_heap = priority_queue<T, vector<T>, greater<T>>;
template<class T> using vec = vector<T>;
template<class T> using vvec = vec<vec<T>>;
template<class T> using vvvec = vec<vvec<T>>;
template<class T> using vvvvec = vvec<vvec<T>>;

constexpr ld EPS = 1e-10;
ld Pi = acos(-1);
constexpr int INF = 1001001001;
constexpr ll LINF = 1001001001001001001ll;
constexpr ll MOD = (1) ? 998244353 : 1e9+7;
constexpr int NIL = -1;
constexpr int pm[2] = {1, -1};
constexpr int dy[4] = {0, 1, 0, -1};
constexpr int dx[4] = {1, 0, -1, 0};
constexpr int dy8[8] = {0, 1, 1, 1, 0, -1, -1, -1};
constexpr int dx8[8] = {1, 1, 0, -1, -1, -1, 0, 1};

ll cel(ll a, ll b){ return (a + b - 1) / b;}
ll Gcd(ll a, ll b){ return b ? Gcd(b, a % b) : abs(a);}
ll Lcm(ll a, ll b){ return a / Gcd(a, b) * b;}
template<class T> T powi(T x, ll exp){
    return exp > 0 ? (exp & 1 ? x : 1) * powi(x * x, exp >> 1) : x / x;
}
ll modpow(ll x, ll exp, ll mod){
    x %= mod;
    return exp > 0 ? (exp & 1 ? x : 1) * modpow(x * x, exp >> 1, mod) % mod : 1;
}
template<class T> bool chmin(T &a, T b){ return a > b ? (a = b, true) : 0;}
template<class T> bool chmax(T &a, T b){ return a < b ? (a = b, true) : 0;}

using Pair = pair<ll, ll>;
using Tpl = tuple<int, int, int>;

void Main(){
    
}

signed main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
    return 0;
}
