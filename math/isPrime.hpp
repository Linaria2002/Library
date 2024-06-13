#include<bits/stdc++.h>
using namespace std;

bool isPrime(long long p){
    if(p < 2) return false;
    for(long long i = 2; i * i <= p; i++){
        if(p % i == 0) return false;
    }
    return true;
}