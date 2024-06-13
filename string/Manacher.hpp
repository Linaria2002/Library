#include<bits/stdc++.h>
using namespace std;

vector<int> Manacher(string &s){
    int sz = s.size();
    vector<int> res(sz, 0);
    int i = 0, j = 0;
    while (i < sz) {
        while (i - j >= 0 && i + j < sz && s[i - j] == s[i + j]) ++j;
        res[i] = j;
        int k = 1;
        while (i - k >= 0 && k + res[i - k] < j)
            res[i + k] = res[i - k], ++k;
        i += k; j -= k;
    }
    return res;
}