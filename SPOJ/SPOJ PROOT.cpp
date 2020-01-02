/**
 * phi(p) = p - 1 , if g is primitive root then k = phi , g^k mod p is the smallest power equals to 1 mod p
 * then we need to check if there is a divisor d | phi s.t. g^d = 1 mod p then it's not primitive root
 * check whether phi / p[i] for all primes divides phi != 1 mod p
 * g^d*k = (g^d)^k = (1)^k = 1 mod p
 * link : https://cp-algorithms.com/algebra/primitive-root.html
 * link : http://zobayer.blogspot.com/2010/02/primitive-root.html
 */
#include<bits/stdc++.h>
#define pb push_back
#define all(v) (v).begin() , (v).end()
#define popcnt(x) __builtin_popcount(x)
#define inf 0x3f3f3f3f
#define watch(x) cout << (#x) << " is " << (x) << endl
#define rand() (rand() << 15 | rand())
using namespace std;
typedef long long  ll;
#define EPS 1e-9
#define PI acos(-1.0)


vector<int> fact(int n){
   vector<int> ret;
   for(int i = 2 ; 1ll * i * i <= n ; ++i){
      if(n % i == 0){
         ret.pb(i);
         while(n % i == 0) n /= i;
      }
   }
   if(n != 1)
      ret.pb(n);
   return ret;
}

int Power(int x , int n , int MOD){
   if(n == 1)
      return x % MOD;
   if(n & 1){
      return (1ll * (x % MOD) * (Power(x , n - 1 , MOD) % MOD)) % MOD;
   }
   else {
      int y = Power(x , n / 2 , MOD);
      return (1ll * y * y) % MOD;
   }
}

int main() {
#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
#endif
   ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
   int p , n;
   while(cin >> p >> n && p && n){
      int phi = p - 1;
      vector<int> v = fact(phi);

      for(int i = 0 ; i < n ; ++i){
         int g;
         cin >> g;

         bool bad = false;
         for(int d : v){
            if(Power(g , phi / d , p) == 1)
               bad = true;
         }

         cout << (bad ? "NO\n" : "YES\n");

      }
   }
}