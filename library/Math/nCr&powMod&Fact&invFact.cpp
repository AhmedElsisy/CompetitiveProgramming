const int N = 2e7 + 5 , MOD = 1e9 + 7;
int fact[N] , invfact[N];

int mul(int a , int b , int m){
    return (1LL * (a % m) * (b % m)) % m;
}

int add(int a , int b , int m){
    return (1LL * (a % m) + (b % m)) % m;
}

int powMOD(int x , int n , int m = MOD){
    if(!n)return 1;
    int ret = 1;
    if(n & 1)ret = mul(x , powMOD(x , n - 1 , m) , m);
    else{
        int y = powMOD(x , n / 2 , m);
        ret = mul(y , y , m);
    }
    return ret;
}

int nCr(int n , int r){
    if(r < 0 || r > n)return 0;
    return mul(mul(fact[n] , invfact[r] , MOD) , invfact[n - r] , MOD);
}

void pre(){
    fact[0] = invfact[0] = 1;
    for(int i = 1 ; i < N ; ++i)
        fact[i] = mul(i % MOD , fact[i - 1] , MOD);

    invfact[N - 1] = powMOD(fact[N - 1] , MOD - 2 , MOD);
    for(int i = N - 2; ~i ; --i)
        invfact[i] = mul(invfact[i + 1] , (i + 1) % MOD , MOD);
}
