// O(NlogN)
vector<vector<int>> divisors(int N){
    vector<vector<int>> res(N + 1);
    for(int i = 1; i <= N; i++){
        for(int j = i; j <= N; j += i){
            res[j].emplace_back(i);
        }
    }
    return res;
}