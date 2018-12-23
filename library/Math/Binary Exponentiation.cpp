long long power(long long x , long long n){         // 13 = 8 + 4 + 1 , and its binary = 1101
    long long ret = 1;
    while(n){
        if(n & 1)
            ret *= x;
        x *= x;
        n >>= 1;
    }
    return ret;
}
