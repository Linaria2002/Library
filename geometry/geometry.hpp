#include<bits/stdc++.h>
using namespace std;

namespace geometry{
    using Real = long double;
    using Point = complex<Real>;
    constexpr Real EPS = 1e-10;
    Real Pi = acos(-1);

    istream& operator>>(istream& is, Point& p){
        Real a, b; is >> a >> b;
        p = Point(a, b);
        return is;
    }
    ostream& operator<<(ostream& os, const Point& p){
        return os << real(p) << " " << imag(p);
    }
    bool equals(const Real& a, const Real& b){
        return fabs(a - b) < EPS;
    }
    Point operator*(const Point& p, const Real& d){
        return Point(real(p) * d, imag(p) * d);
    }
    Real cross(const Point& a, const Point& b){
        return real(a) * imag(b) - imag(a) * real(b);
    }
    Real dot(const Point& a, const Point& b){
        return real(a) * real(b) + imag(a) * imag(b);
    }
    int sign(const Real &x){
        return x >= EPS ? +1 : x <= -EPS ? -1 : 0;
    }
    int ccw(const Point &a, const Point &b, const Point &p){
        if(sign(cross(b - a, p - a)) == +1) return +1; // conter clockwise
        if(sign(cross(b - a, p - a)) == -1) return -1; // clockwise
        if(sign(dot(b - a, p - a)) == -1) return +2;   // p--a--b online back
        if(sign(dot(a - b, p - b)) == -1) return -2;   // a--b--p online front
        return 0;                                      // a--p--b on segment
    }
    Point projection(const Point& a, const Point& b, const Point& p){
        Real t = dot(p - a, a - b) / norm(a - b);
        return a + (a - b) * t;
    }
    Point reflection(const Point& a, const Point& b, const Point& p){
        return p + (projection(a, b, p) - p) * 2;
    }
}

