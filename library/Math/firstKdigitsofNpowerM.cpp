// returns first k digits of n ^ m
int getfirstKdigits(int n , int m , int k){
    long double product = 1.0L * m * log10(1.0L * n);
    long double decimal_part = product - floor(product);
    decimal_part = pow(10.0L, decimal_part);
    long long digits = pow(10.0L, k - 1);
    int firstK = decimal_part * digits;
    return firstK;
}
