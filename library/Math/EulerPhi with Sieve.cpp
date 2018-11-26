const int N = 100005;

vi primes;
bool p[N];

void sieve(){
    p[0] = p[1] = true;
    for(int i = 2 ; i < N ; ++i){
        if(!p[i]){
            for(int j = i * 2 ; j < N ; j += i)p[j] = true;
            primes.pb(i);
        }
    }
}

int EulerPhi(int n){
    if(n == 1)return 0;
    int indx = 0 , PF = primes[indx++] , ans = n;
    while(1LL * PF * PF <= n){
        if(n % PF == 0)ans -= ans / PF;
        while(n % PF == 0)n /= PF;
        PF = primes[indx++];
    }
    if(n != 1)ans -= ans / n;
    return ans;
}
