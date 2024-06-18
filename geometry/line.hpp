#pragma once
#include "geometry.hpp"

namespace geometry{
    struct Line{
        Point a, b;
        Line() = default;
        Line(const Point& a, const Point& b) : a(a), b(b) {}
        Line(const Real& A, const Real& B, const Real& C){ // Ax+By=C
            if(equals(A, 0)){
                assert(!equals(B, 0));
                a = Point(0, C / B), b = Point(1, C / B);
            }
            else if(equals(B, 0)){
                a = Point(C / A, 0), b = Point(C / A, 1);
            }
            else{
                a = Point(0, C / B), b = Point(C / A, 0);
            }
        }
        friend istream& operator>>(istream& is, Line& l) {
            return is >> l.a >> l.b;
        }
        friend ostream& operator<<(ostream& os, Line& l) {
            return os << l.a << " to " << l.b;
        }
    };
    bool isOrthogonal(const Line& p, const Line& q){
        return equals(dot(p.b - p.a, q.b - q.a), 0.0);
    }
    bool isParallel(const Line& p, const Line& q){
        return equals(cross(p.b - p.a, q.b - q.a), 0.0);
    }
    Point cross_point(const Line &l, const Line &m){
        Real A = cross(l.b - l.a, m.b - m.a);
        Real B = cross(l.b - l.a, l.b - m.a);
        if(equals(abs(A), 0.0) && equals(abs(B), 0.0)) return m.a;
        assert(!equals(abs(A), 0.0));
        return m.a + (m.b - m.a) * B / A;
    }
}
