#include <bits/stdc++.h>
#define pb push_back
#define all(v) (v).begin() , (v).end()
#define popcnt(x) __builtin_popcount(x)
#define inf 0x3f3f3f3f
#define watch(x) cout << (#x) << " is " << (x) << endl

using namespace std;
typedef long long  ll;

int mul(int a , int b , int m){
    return (1LL * (a % m) * (b % m)) % m;
}

int add(int a , int b , int m){
    return (1LL * (a % m) + (b % m)) % m;
}

int powMOD(int x , int n , int m){
    if(!n)return 1;
    int ret = 1;
    if(n & 1)ret = mul(x , powMOD(x , n - 1 , m) , m);
    else{
        int y = powMOD(x , n / 2 , m);
        ret = mul(y , y , m);
    }
    return ret;
}

// returns first k digits of n ^ m
int getfirstKdigits(int n , int m , int k){
    long double product = 1.0L * m * log10(1.0L * n);
    long double decimal_part = product - floor(product);
    decimal_part = pow(10.0L, decimal_part);
    long long digits = pow(10.0L, k - 1);
    int firstK = decimal_part * digits;
    return firstK;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r" , stdin);
#endif
//    ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n , k;
        cin >> n >> k;
        int m1 = 1 , cnt = k;
        while(cnt--)
            m1 *= 10;
        int lastK = powMOD(2 , n - 1 , m1);
        int firstK = getfirstKdigits(2 , n - 1 , k);
        cout << lastK + firstK << "\n";
    }

}
