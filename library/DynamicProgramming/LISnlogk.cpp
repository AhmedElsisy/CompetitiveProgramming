vector<int> LIS(vector<int> &a){    // O(n log k) k is the longest increasing subsequence
    int n = (int)a.size();
    vector<int> p(n , -1) , d(n , -1);  // parent[] , d[i] is the maximum subsequence ending in i
    vector<int> lis , lis_indexes;
    for(int i = 0 ; i < n ; ++i){
        int j = lower_bound(lis.begin() , lis.end() , a[i]) - lis.begin();
        if(j == (int)lis.size())lis.push_back(a[i]) , lis_indexes.pb(i);
        else lis[j] = a[i] , lis_indexes[j] = i;

        d[i] = j + 1;
        p[i] = (j ? lis_indexes[j - 1] : -1);
    }
    int lis_sz = *max_element(d.begin() , d.end()) , lst = -1;
    for(int i = 0 ; i < n ; ++i){
        if(d[i] == lis_sz){
            lst = i;
        }
    }
    vector<int> ret;
    while(lst != -1)
        ret.push_back(a[lst]) , lst = p[lst];
    reverse(ret.begin() , ret.end());
    return ret;
}
