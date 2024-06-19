class RollHash{
    const int mod1 = 1e9+7;
    const int mod2 = 998244353;
    const int basecond = 557;
    long long powb1 = 1, powb2 = 1;
    long long invb1 = modinv(basecond, mod1), invb2 = modinv(basecond, mod2);
    long long modinv(long long a, long long mod){
        long long b = mod, y = 1, x = 0;
        while(b){
            long long t = a / b;
            a -= t * b; swap(a, b);
            y -= t * x; swap(y, x);
        }
        y %= mod;
        if(y < 0) y += mod;
        return y;
    }
    void increment(){
        powb1 *= basecond, powb2 *= basecond;
        if(powb1 >= mod1) powb1 %= mod1;
        if(powb2 >= mod2) powb2 %= mod2;
    }
    void decrement(){
        powb1 *= invb1, powb2 *= invb2;
        if(powb1 >= mod1) powb1 %= mod1;
        if(powb2 >= mod2) powb2 %= mod2;
    }

    public:
    pair<long long, long long> hash = {0, 0};
    void push_front(char c){
        hash.first = (hash.first * basecond + c) % mod1;
        hash.second = (hash.second * basecond + c) % mod2;
        increment();
    }
    void pop_front(char c){
        decrement();
        hash.first = (hash.first - c + mod1) * invb1 % mod1;
        hash.second = (hash.second - c + mod2) * invb2 % mod2;
    }
    void push_back(char c){
        hash.first = (hash.first + powb1 * c) % mod1;
        hash.second = (hash.second + powb2 * c) % mod2;
        increment();
    }
    void pop_back(char c){
        decrement();
        hash.first = (hash.first - (c * powb1 % mod1) + mod1) % mod1;
        hash.second = (hash.second - (c * powb2 % mod2) + mod2) % mod2;
    }
    bool same(RollHash h2){
        return hash == h2.hash;
    }
};