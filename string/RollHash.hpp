class RollHash{
    const int mod1 = 1e9+7;
    const int mod2 = 998244353;
    const int base = 557;
    ll powb1 = 1, powb2 = 1;
    ll invb1 = modinv(base, mod1), invb2 = modinv(base, mod2);
    ll modinv(ll a, ll mod){
        ll b = mod, y = 1, x = 0;
        while(b){
            ll t = a / b;
            a -= t * b; swap(a, b);
            y -= t * x; swap(y, x);
        }
        y %= mod;
        if(y < 0) y += mod;
        return y;
    }
    void increment(){
        powb1 *= base, powb2 *= base;
        if(powb1 >= mod1) powb1 %= mod1;
        if(powb2 >= mod2) powb2 %= mod2;
    }
    void decrement(){
        powb1 *= invb1, powb2 *= invb2;
        if(powb1 >= mod1) powb1 %= mod1;
        if(powb2 >= mod2) powb2 %= mod2;
    }

    public:
    pair<ll, ll> hash = {0, 0};
    void push_front(char c){
        hash.fi = (hash.fi * base + c) % mod1;
        hash.se = (hash.se * base + c) % mod2;
        increment();
    }
    void pop_front(char c){
        decrement();
        hash.fi = (hash.fi - c + mod1) * invb1 % mod1;
        hash.se = (hash.se - c + mod2) * invb2 % mod2;
    }
    void push_back(char c){
        hash.fi = (hash.fi + powb1 * c) % mod1;
        hash.se = (hash.se + powb2 * c) % mod2;
        increment();
    }
    void pop_back(char c){
        decrement();
        hash.fi = (hash.fi - (c * powb1 % mod1) + mod1) % mod1;
        hash.se = (hash.se - (c * powb2 % mod2) + mod2) % mod2;
    }
    bool same(RollHash h2){
        return hash == h2.hash;
    }
};