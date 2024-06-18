template <int mod> struct modint{
    long long x;
    modint() : x(0) {}
    modint(long long _x){ x = _x % mod; if(x < 0) x += mod; }
    constexpr modint operator-() const { return modint(-x); }
    constexpr modint& operator+=(const modint& a){ if ((x += a.x) >= mod) x -= mod; return *this; }
    constexpr modint& operator-=(const modint& a){ if ((x += mod - a.x) >= mod) x -= mod; return *this; }
    constexpr modint& operator*=(const  modint& a){ (x *= a.x) %= mod; return *this; }
    constexpr modint& operator/=(const modint& a){ return (*this) *= a.inv(); }
    constexpr modint operator+(const modint& a) const { return modint(*this) += a; }
    constexpr modint operator-(const modint& a) const { return modint(*this) -= a; }
    constexpr modint operator*(const modint& a) const { return modint(*this) *= a; }
    constexpr modint operator/(const modint& a) const { return modint(*this) /= a; }
    constexpr bool operator==(const modint& a) const { return (*this).x == a.x; }
    constexpr bool operator!=(const modint& a) const { return (*this).x != a.x; }
    friend istream& operator>>(istream& is, modint& m){ is >> m.x; m = modint<mod>(m.x); return is; }
    friend ostream& operator<<(ostream& os, const modint& m){ os << m.x; return os; }
    constexpr const modint inv() const {
        modint res(1);
        modint x = *this;
        for(long long exp = mod-2; exp; exp >>= 1){
            if(exp & 1){ res *= x; } x *= x;
        }
        return res;
    }
};
