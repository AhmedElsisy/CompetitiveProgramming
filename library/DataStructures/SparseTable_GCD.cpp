const int N = 1e5 + 4 , LG = log2(N) + 1;
int gcd[N][LG];
int n , getlg[N];
vector<int> a;
// take care of long long

void pre(){
    for(int i = 1 ; i < N ; ++i)
        getlg[i] = (int)log2(i);
}

void build(){
    int lg = getlg[n];

    for(int i = 0 ; i < n ; ++i)
        gcd[i][0] = a[i];           // base case

    for(int j = 1 ; j <= lg ; ++j){
        for(int i = 0 ; i + (1 << j) - 1 < n ; ++i){
            gcd[i][j] = __gcd(gcd[i][j - 1] , gcd[i + (1 << (j - 1))][j - 1]);
        }
    }

}

int getGCD(int l , int r){          // query in log(N) s.t. N = max(gcd[l][lg] , gcd[l + dif][lg])
    int sz = r - l + 1 , lg = getlg[sz] , dif = sz - (1 << lg);
    return __gcd(gcd[l][lg] , gcd[l + dif][lg]);
}

