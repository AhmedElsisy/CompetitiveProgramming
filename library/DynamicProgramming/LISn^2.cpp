// O(n ^ 2)
int LIS(vector<int> &a){
    int n = (int)a.size();
    vector<int> res(n , 1);

    for(int i = 0 ; i < n ; ++i){
        for(int j = i + 1 ; j < n ; ++j){
            if(a[j] >= a[i]) // strictly increasing ">" edit here
                res[j] = max(res[j] , res[i] + 1);
        }
    }

    return *max_element(res.begin() , res.end());
}
