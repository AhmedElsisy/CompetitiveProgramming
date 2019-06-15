#define Matrix vector<vector<int>>
const int MOD = 1e9 + 7;

Matrix matrixMul(Matrix a , Matrix b){
    int p = a.size() , q = a[0].size() , r = b.size();
    Matrix ret(p , vector<int>(r , 0));
    for(int i = 0 ; i < p ; ++i){
        for(int j = 0 ; j < r ; ++j){
            for(int k = 0 ; k < q ; ++k){
                ret[i][j] += (1ll * a[i][k] * b[k][j]) % MOD;
                ret[i][j] %= MOD;
            }
        }
    }
    return ret;
}

Matrix matrixPow(Matrix base , int n){
    Matrix ret(base.size() , vector<int>(base.size()));
    for(int i = 0 ; i < base.size() ; ++i)
        ret[i][i] = 1;
    while(n){
        if(n & 1)ret = matrixMul(ret , base);
        base = matrixMul(base , base);
        n >>= 1;
    }
    return ret;
}
