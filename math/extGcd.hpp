#include<bits/stdc++.h>
using namespace std;

// Ax + By = C (0 <= x < B)
pair<int64_t, int64_t> extGcd(int64_t A, int64_t B, int64_t C = 1){
    if(C == 0) return {0, 0};
    if(B < 0) A = -A, B = -B, C = -C;
    int64_t d = (A % B + B) % B, e = B, x = 1, y = 0;
    while(e){
        int64_t t = d / e;
        d -= t * e; swap(d, e);
        x -= t * y; swap(x, y);
    }
    if(d > 1){
        if(C % d != 0) return {-1, -1};
        A /= d, B /= d, C /= d;
    }
    x = x % B * C % B; if(x < 0) x += B;
    y = (C - A * x) / B;
    return {x, y};
}