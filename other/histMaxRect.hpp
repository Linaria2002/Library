// O(|A|)
// returns [L_i, R_i)
template<class T> vector<pair<int, int>> histMaxRect(vector<T> A){
    int N = A.size();
    static vector<pair<int, int>> res(N);
    static vector<int> val(N);
    static stack<int> st;
    
    for(int _ = 0; _ < 2; _++){
        for(int i = 0; i < N; i++) val[i] = i;

        // val[i] := ヒストグラムの i 番目を右端とする長 方形の幅の最大値
        for(int i = 0; i < N; i++){
            while(1){
                if(st.empty()){
                    val[i] = 0; break;
                }
                else if(A[st.top()] < A[i]){
                    val[i] = val[st.top() + 1]; break;
                }
                else st.pop();
            }
            st.push(i);
        }
        while(!st.empty()) st.pop();

        if(_ == 0){
            for(int i = 0; i < N; i++) res[i].first = val[i];
            reverse(A.begin(), A.end());
        }
        else{
            for(int i = 0; i < N; i++) res[i].second = N - val[N - i - 1];
        }
    }
    return res;
}