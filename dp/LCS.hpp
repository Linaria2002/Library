template<class T> T LCS(T s, T t){
    int H = s.size(), W = t.size();
    vector<vector<int>> dp(H + 1, vector<int>(W + 1, 0));
    T res;
    for(int i = 1; i <= H; i++){
        for(int j = 1; j <= W; j++){
            if(s[i - 1] == t[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
        }
    }
    for(int i = H, j = W; dp[i][j]; i--){
        if(dp[i - 1][j] < dp[i][j]){
            res.push_back(s[i - 1]);
            while(dp[i][j - 1] == dp[i][j]) j--;
            j--;
        }
    }
    reverse(res.begin(), res.end());
    return res;
}