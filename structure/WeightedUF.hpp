template<class Abel> struct WeightedUF{
    vector<int> par;
    vector<int> rank;
    vector<Abel> diff_weight;
    vector<bool> broken;

    WeightedUF(int n, Abel SUM_UNITY = 0){
        par.resize(n); rank.resize(n);
        diff_weight.resize(n, SUM_UNITY); broken.resize(n);
        for(int i = 0; i < n; ++i) par[i] = i;
    }
    int root(int x){
        if(par[x] == x){
            return x;
        }
        else{
            int r = root(par[x]);
            diff_weight[x] += diff_weight[par[x]];
            broken[x] = broken[par[x]];
            return par[x] = r;
        }
    }
    Abel weight(int x){
        root(x);
        return diff_weight[x];
    }
    bool isSame(int x, int y){
        return root(x) == root(y);
    }
    bool isBroken(int x){
        root(x);
        return broken[x];
    }
    bool merge(int x, int y, Abel w){
        w += weight(x); w -= weight(y);
        x = root(x); y = root(y);
        if(x == y){
            if(w) broken[x] = 1;
            return false;
        }
        if(rank[x] < rank[y]) swap(x, y), w = -w;
        if(rank[x] == rank[y]) ++rank[x];
        par[y] = x;
        if(broken[y]) broken[x] = 1;
        diff_weight[y] = w;
        return true;
    }
    Abel diff(int x, int y){
        return weight(y) - weight(x);
    }
};