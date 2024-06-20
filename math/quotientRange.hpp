template<class T> vector<pair<pair<T, T>, T>> quotientRange(T N){
    vector<pair<pair<T, T>, T>> res;
    T M;
    for(M = 1; M * M <= N; M++){
        res.emplace_back(make_pair(M, M), N / M);
    }
    for(T i = M; i >= 1; i--){
        T L = N / (i + 1) + 1;
        T R = N / i;
        if(L <= R && res.back().first.second < L) res.emplace_back(make_pair(L, R), N / L);
    }
    return res;
}