template<class T>
class BIT{
    int size;
    vector<T> dat;
    T sum(int idx){
        T res = 0;
        for(; idx > 0; idx -= idx & -idx) res += dat[idx];
        return res;
    }
    public:
    BIT(int N) : size(N), dat(N + 1) {}
    BIT(int N, const vector<int> &V): size(N), dat(N + 1) {
        for(int i = 1; i <= size; i++){
            dat[i] += V[i - 1];
            if(i + (i & -i) <= size) dat[i + (i & -i)] += dat[i];
        }
    }
    void add(int idx, T x){
        for(idx++; idx <= size; idx += idx & -idx) dat[idx] += x;
    }
    T query(int Lidx, int Ridx){
        return sum(Ridx) - sum(Lidx);
    }
};