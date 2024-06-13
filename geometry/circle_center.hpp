#include<bits/stdc++.h>
using namespace std;

template<class T>
complex<T> cricle_center(complex<T> a, complex<T> b, complex<T> c){
    complex<T> res = {0, 0};
    T div = 2*(a.x-b.x)*(a.y-c.y) - 2*(a.x-c.x)*(a.y-b.y);
    if(div == 0) return {1e18, 1e18};

    res.x += (a.y-b.y)*(c.x*c.x - a.x*a.x + c.y*c.y - a.y*a.y);
    res.x -= (a.y-c.y)*(b.x*b.x - a.x*a.x + b.y*b.y - a.y*a.y);
    res.x /= div;
    res.y += (a.x-c.x)*(b.x*b.x - a.x*a.x + b.y*b.y - a.y*a.y);
    res.y -= (a.x-b.x)*(c.x*c.x - a.x*a.x + c.y*c.y - a.y*a.y);
    res.y /= div;

    return res;
}
