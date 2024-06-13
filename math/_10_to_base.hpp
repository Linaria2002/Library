#include<bits/stdc++.h>
using namespace std;

string _10_to_base(long long N, int base){
    string res;
    for(; N > 0; N /= base){
        res += (N % base) + '0';
    }
    reverse(res.begin(), res.end());
    return res;
}
