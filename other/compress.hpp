// vals[vec[id]] to decopress
template<class T> vector<T> compress(vector<T> &vec){
    int sz = vec.size();
    vector<T> vals = vec;
    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(). vals.end()), vals.end());
    for(int i = 0; i < sz; i++){
        vec[i] = lower_bound(vals.begin(), vals.end(), vec[i]) - vals.begin();
    }
    return vals;
}