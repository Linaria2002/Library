vector<int> zeta_algorithm(string &s){
    vector<int> prefix(s.size());
    for(int i = 1, j = 0; i < (int)s.size(); i++) {
        if(i + prefix[i - j] < j + prefix[j]) {
            prefix[i] = prefix[i - j];
        }
        else{
            int k = max(0, j + prefix[j] - i);
            while(i + k < (int)s.size() && s[k] == s[i + k]) ++k;
            prefix[i] = k;
            j = i;
        }
    }
    prefix[0] = (int) s.size();
    return prefix;
}