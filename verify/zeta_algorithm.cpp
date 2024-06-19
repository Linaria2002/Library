// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/zalgorithm

#include <bits/stdc++.h>
#include "../string/zeta_algorithm.hpp"

int main(){
    int N; cin >> N;
    string s; cin >> s;
    vector<int> ans = zeta_algorithm(s);
    for(int i = 0; i < N; i++){
        cout << ans[i];
        if(i != N - 1) cout << ' ';
    }
    cout << endl;
}