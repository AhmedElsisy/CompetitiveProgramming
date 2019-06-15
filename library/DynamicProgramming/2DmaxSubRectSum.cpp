int maxSubRectSum(vector<vector<int> > &a){
    int n = (int)a.size();
    for(int i = 0 ; i < n ; ++i){
        for(int j = 0 ; j < n ; ++j){
            if(j)a[i][j] += a[i][j - 1];
        }
    }

    int ret = 0; // empty sub-rectangle
    for(int i = 0 ; i < n ; ++i){
        for(int j = i ; j < n ; ++j){
            int currentSum = 0;
            for(int r = 0 ; r < n ; ++r){
                if(i > 0)currentSum += a[r][j] - a[r][i - 1];
                else currentSum += a[r][j];
                if(currentSum < 0)currentSum = 0;
                ret = max(ret , currentSum);
            }
        }
    }
    return ret;
}
