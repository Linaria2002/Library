template<class T>
struct Sum2d{
    int H, W;
    vector<vector<T>> dat;

    Sum2d() = default;
    Sum2d(vector<vector<T>> &V) : H(V.size()), W(V[0].size()), dat(H + 1, vector<T>(W + 1)) {
        for(int i = 0; i < H; i++){
            for(int j = 0; j < W; j++){
                dat[i + 1][j + 1] = V[i][j] + dat[i + 1][j] + dat[i][j + 1] - dat[i][j];
            }
        }
    }

    // [r0, r1), [c0, c1)
    T query(int r0, int c0, int r1, int c1){
        return dat[r1][c1] - dat[r1][c0] - dat[r0][c1] + dat[r0][c0];
    }
};