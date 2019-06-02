// Primes less than 1000:
// 2 3 5 7 11 13 17 19 23 29 31 37
// 41 43 47 53 59 61 67 71 73 79 83 89
// 97 101 103 107 109 113 127 131 137 139 149 151
// 157 163 167 173 179 181 191 193 197 199 211 223
// 227 229 233 239 241 251 257 263 269 271 277 281
// 283 293 307 311 313 317 331 337 347 349 353 359
// 367 373 379 383 389 397 401 409 419 421 431 433
// 439 443 449 457 461 463 467 479 487 491 499 503
// 509 521 523 541 547 557 563 569 571 577 587 593
// 599 601 607 613 617 619 631 641 643 647 653 659
// 661 673 677 683 691 701 709 719 727 733 739 743
// 751 757 761 769 773 787 797 809 811 821 823 827
// 829 839 853 857 859 863 877 881 883 887 907 911
// 919 929 937 941 947 953 967 971 977 983 991 997

// Other primes:
// The largest prime smaller than 10 is 7.
// The largest prime smaller than 100 is 97.
// The largest prime smaller than 1000 is 997.
// The largest prime smaller than 10000 is 9973.
// The largest prime smaller than 100000 is 99991.
// The largest prime smaller than 1000000 is 999983.
// The largest prime smaller than 10000000 is 9999991.
// The largest prime smaller than 100000000 is 99999989.
// The largest prime smaller than 1000000000 is 999999937.
// The largest prime smaller than 10000000000 is 9999999967.
// The largest prime smaller than 100000000000 is 99999999977.
// The largest prime smaller than 1000000000000 is 999999999989.
// The largest prime smaller than 10000000000000 is 9999999999971.
// The largest prime smaller than 100000000000000 is 99999999999973.
// The largest prime smaller than 1000000000000000 is 999999999999989.
// The largest prime smaller than 10000000000000000 is 9999999999999937.
// The largest prime smaller than 100000000000000000 is 99999999999999997.
// The largest prime smaller than 1000000000000000000 is 999999999999999989.
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

