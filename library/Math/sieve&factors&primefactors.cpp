
const int N = 1e3 + 4; // set upper bound

vector<int> primes;
bitset<N> p;

// call it in main
void sieve(){
    p.set();
    p[0] = p[1] = 0;
    for(int i = 2 ; i < N ; ++i){
        if(p[i]){
            for(int j = i * 2 ; j < N ; j += i)p[j] = 0;
            primes.pb(i);
        }
    }
}


vector<int> getfactors(int n){  // long long
    vector<int> ret;
    for(int i = 1 ; 1ll * i * i <= n ; ++i){
        if(n % i == 0){
            ret.pb(i);
            if(i != n / i)ret.pb(n / i);
        }
    }
    return ret;
}


vector<int> getprimefactors(int n){  // long long
    vector<int> ret;
    int indx = 0 , PF = primes[indx++];
    while(1ll * PF * PF <= n){
        while(n % PF == 0)n /= PF , ret.pb(PF);
        PF = primes[indx++];
    }
    if(n > 1)ret.pb(n);
    return ret;
}

