template<class T>
class Doubling{
    using Fnc = function<T(T, T)>;
    Fnc fnc = [](T a, T b){return a + b;};
    vector<vector<int>> next;
    vector<vector<T>> val;
    int N, logk;

    public:
    Doubling(int _N, int _logk) : N(_N), logk(_logk),
        next(_logk, vector<int>(_N)), val(_logk, vector<T>(_N)) {}
    void build(vector<int> &nx, vector<T> &vl){
        if((int)nx.size() != N || (int)vl.size() != N) return;
        for(int i = 0; i < N; i++){
            next[0][i] = nx[i];
            val[0][i] = vl[i];
        }
        for(int i = 0; i < logk - 1; i++){
            for(int j = 0; j < N; j++){
                next[i + 1][j] = next[i][next[i][j]];
                val[i + 1][j] = fnc(val[i][j], val[i][next[i][j]]);
            }
        }
    }
    pair<int, T> query(int X, T Y, ll K){
        for(int i = 0; K > 0; i++, K >>= 1){
            if(K & 1){
                Y = fnc(Y, val[i][X]);
                X = next[i][X];
            }
        }
        return make_pair(X, Y);
    }
};