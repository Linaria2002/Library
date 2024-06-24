#pragma once
template<class T> pair<pair<T, T>, bool> linearEquation(T a, T b, T c, T d, T e, T f, T eps = 1e-12){
    T Q = (a * e - b * d);
    if(abs(Q) <= eps)  return make_pair(make_pair(0, 0), false);
    T X = (c * e - b * f) / Q;
    T Y = (a * f - c * d) / Q;
    return make_pair(make_pair(X, Y), true);
}