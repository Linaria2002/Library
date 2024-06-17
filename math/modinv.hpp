// ※テンプレート依存
// find y(0 <= y < mod) where modx + ay = 1
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