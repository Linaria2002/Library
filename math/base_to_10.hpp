long long base_to_10(string s, int base){
    long long res = 0, x = 1;
    for(int i = (int)s.size() - 1; i >= 0; i--){
        res += (s[i] - '0') * x;
        x *= base;
    }
    return res;
}
