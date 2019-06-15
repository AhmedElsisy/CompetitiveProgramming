#include <bits/stdc++.h>
#define pb push_back
#define all(v) (v).begin() , (v).end()
#define popcnt(x) __builtin_popcount(x)
#define inf 0x3f3f3f3f
#define watch(x) cout << (#x) << " is " << (x) << endl
#define rand() (rand() << 15 | rand())
#define Matrix vector<vector<int>>
using namespace std;
int MOD = 1;

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

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt" , "r" , stdin);
#endif
    ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);
    int n , m;
    while(cin >> n >> m){
        MOD = (1 << m);
        if(n == 0)
            cout << 0 << endl;
        else if(n == 1)
            cout << 1 << endl;
        else{
            Matrix mat1(2 , vector<int>(1));
            mat1[0][0] = 1;
            mat1[1][0] = 0;

            Matrix mat2(2 , vector<int>(2));
            mat2[0][0] = 1;
            mat2[0][1] = 1;
            mat2[1][0] = 1;
            mat2[1][1] = 0;

            Matrix nth = matrixPow(mat2 , n - 1);
            Matrix res = matrixMul(nth , mat1);
            cout << res[0][0] << endl;
        }
    }
}
