vector<int> prefix_function(string s){
    int n = (int)s.size();
    vector<int> prefix(n , 0);
    for(int i = 1 ; i < n ; ++i){
        int j = prefix[i - 1];
        while(j > 0 && s[i] != s[j])
            j = prefix[j - 1];
        if(s[i] == s[j])
            ++j;
        prefix[i] = j;
    }
    return prefix;
}

int count_occurences(string P , string T){
    int n = (int)T.size() , cnt = 0;
    vector<int> prefix = prefix_function(P);
    vector<int> match(n , 0);
    for(int i = 0 , j = 0 ; i < n ; ++i){
        while(j > 0 && T[i] != P[j])j = prefix[j - 1];
        if(T[i] == P[j])
            ++j;
        match[i] = j;
        if(j == (int)P.size())++cnt , j = prefix[j - 1];
    }
    return cnt;
}

vector<int> get_occurences(string P , string T){
    int n = (int)T.size();
    vector<int> prefix = prefix_function(P);
    vector<int> match(n , 0);
    vector<int> ret;
    for(int i = 0 , j = 0 ; i < n ; ++i){
        while(j > 0 && T[i] != P[j])j = prefix[j - 1];
        if(T[i] == P[j])
            ++j;
        match[i] = j;
        if(j == (int)P.size())ret.pb(i - (int)P.size() + 1) , j = prefix[j - 1];
    }
    return ret;
}
