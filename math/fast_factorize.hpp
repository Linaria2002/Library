class fast_factorize{
    int size;
    vector<int> min_factor;

    public:
    fast_factorize(int N) : size(N + 1), min_factor(N + 1) {
        for(int i = 0; i < size; i++) min_factor[i] = i;
        for(int i = 2; i < size; i++){
            if(min_factor[i] == i){
                for(int j = i + i; j < size; j += i){
                    if(min_factor[j] == j) min_factor[j] = i;
                }
            }
        }
    }

    vector<pair<int, int>> factorize(int X){
        vector<pair<int, int>> res;
        while(1){
            if(X < 2) break;
            if(min_factor[X] != X){
                int m = min_factor[X];
                int cnt = 0;
                while(min_factor[X] == m){
                    X /= m;
                    cnt++;
                }
                res.emplace_back(make_pair(m, cnt));
            }
            else{
                res.emplace_back(make_pair(X, 1));
                break;
            }
        }
        return res;
    }
};