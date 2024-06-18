// find y(0 <= y < mod) where modx + ay = 1
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