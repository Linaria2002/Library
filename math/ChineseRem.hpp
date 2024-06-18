long long ExtGcd(long long a, long long b, long long &x, long long &y){
    long long d = a;
    if(b != 0){
        d = ExtGcd(b, a % b, y, x);
        y -= (a / b) * x;
    }
    else{
        x = 1, y = 0;
    }
    return d;
}

pair<long long, long long> ChineseRem(vector<long long> &b, vector<long long> &m) {
    long long r = 0, M = 1;
    for (int i = 0; i < (int)b.size(); ++i) {
        long long p, q;
        long long d = ExtGcd(M, m[i], p, q); // p is inv of M/d (mod. m[i]/d)
        if ((b[i] - r) % d != 0) return make_pair(0, -1);
        long long tmp = (b[i] - r) / d * p % (m[i]/d);
        r += M * tmp;
        M *= m[i]/d;
    }
    return make_pair((r % M + M) % M, M);
}
