#include<bits/stdc++.h>
using namespace std;

template<class T> struct Mosalgo{
    void MoSort(vec<tuple<int, int, int>> &Q, int N){
        const int M = sqrt(N);
        sort(all(Q), [&M](const tuple<int, int, int>& a, const tuple<int, int, int>& b){
            int a0 = get<0>(a) / M, b0 = get<0>(b) / M;
            if(a0 < b0) return true;
            if(a0 == b0)
                return a0 & 1 ? get<1>(a) > get<1>(b) : get<1>(a) < get<1>(b);
            return false;
        });
    }

    void shift(int& s, int g, bool r, vector<ll>& A, T& num, long long& val){
        if(r){
            while(s < g){
                s++;
                val += max(0ll, num[A[s]] * (num[A[s]] - 1) / 2);
                num[A[s]]++;
            }
            while(g < s){
                num[A[s]]--;
                val -= max(0ll, num[A[s]] * (num[A[s]] - 1) / 2);
                s--;
            }
        }
        else{
            while(g < s){
                s--;
                val += max(0ll, num[A[s]] * (num[A[s]] - 1) / 2);
                num[A[s]]++;
            }
            while(s < g){
                num[A[s]]--;
                val -= max(0ll, num[A[s]] * (num[A[s]] - 1) / 2);
                s++;
            }
        }
    }
};