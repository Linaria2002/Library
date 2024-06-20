class RollingHash{
    using u64 = uint64_t;
    using u128 = __uint128_t;
    static const u64 mod = (1ull << 61ull) - 1;
    const u64 base;
    vector<u64> power;

    static u64 generateBase(){
        mt19937_64 mt(chrono::steady_clock::now().time_since_epoch().count());
        uniform_int_distribution<u64> rand(1ull << 32, RollingHash::mod - (1ull << 32));
        return rand(mt);
    }

    static u64 add(u64 a, u64 b){
        a += b;
        if(a >= mod) a -= mod;
        return a;
    }

    static u64 mul(u64 a, u64 b){
        u128 res = u128(a) * b;
        return add(res >> 61, res & mod);
    }

    void expand(int sz){
        if((int)power.size() < sz + 1){
            int pre_sz = (int)power.size();
            power.resize(sz + 1);
            for(int i = pre_sz - 1; i < sz; i++){
                power[i + 1] = mul(power[i], base);
            }
        }
    }

public:
    RollingHash(u64 base = generateBase()) : base(base), power(1, 1) {}
    
    vector<u64> build(const string &str){
        int sz = str.size();
        vector<u64> hashed(sz + 1);
        for(int i = 0; i < sz; i++){
            hashed[i + 1] = add(mul(hashed[i], base), str[i]);
        }
        return hashed;
    }

    template<class T> vector<u64> build(const vector<T> &V){
        int sz = V.size();
        vector<u64> hashed(sz + 1);
        for(int i = 0; i < sz; i++){
            hashed[i + 1] = add(mul(hashed[i], base), V[i]);
        }
        return hashed;
    }
    
    u64 getHash(const vector<u64> &H, int l, int r){
        expand(r - l);
        return add(H[r], mod - mul(H[l], power[r - l]));
    }
    
    int lcp(const vector<u64> &H1, int l1, int r1, const vector<u64> &H2, int l2, int r2){
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