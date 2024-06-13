#include<bits/stdc++.h>
using namespace std;

void MoSort(vector<tuple<int, int, int>> &Q, int N){
    const int M = sqrt(N);
    sort(Q.begin(), Q.end(), [&M](const tuple<int, int, int>& a, const tuple<int, int, int>& b){
        int a0 = get<0>(a) / M, b0 = get<0>(b) / M;
        if(a0 < b0) return true;
        if(a0 == b0)
            return a0 & 1 ? get<1>(a) > get<1>(b) : get<1>(a) < get<1>(b);
        return false;
    });
}