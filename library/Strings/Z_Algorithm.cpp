vector<int> buildZ(string &s){
    int n = (int)s.size();
    vector<int> Z(n , 0);
    int l = 0 , r = 0;
    for(int i = 1 ; i < n ; ++i){
        Z[i] = max(0 , min(Z[i - l] , r - i + 1));
        while(i + Z[i] < n && s[i + Z[i]] == s[Z[i]])
            l = i , r = i + Z[i] , ++Z[i];
    }
    return Z;
}

