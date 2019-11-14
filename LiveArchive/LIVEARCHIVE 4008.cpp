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
const int N = 1000005;
const int MOD = 10;

vector<int> primes;
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

int mul(int a , int b , int m = MOD){
   return (1LL * (a % m) * (b % m)) % m;
}

int add(int a , int b , int m = MOD){
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

long long count_p_in_nfact(long long p, long long n) {
   long long res = 0;
   long long q = p;
   while (q <= n) {
      res += n / q;
      q *= p;
   }
   return res;
}

int main() {
#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin); // comment this
#endif
   ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
   sieve();
   string s;
   while (cin >> s) {
      vector<int> cnt(26, 0);
      for (char c : s)
         cnt[c - 'a']++;
      int lastdigit = 1;
      int twos = -1 , fives = -1;
      for (int p : primes) {
         int cntP = count_p_in_nfact(p, (int) s.size());
         for (int i = 0; i < 26; ++i) {
            if (cnt[i] > 1) {
               cntP -= count_p_in_nfact(p, cnt[i]);
            }
         }
         if(p != 2 && p != 5)lastdigit = mul(lastdigit, powMOD(p, cntP, MOD));
         else{
            if(twos == -1)twos = cntP;
            else fives = cntP;
         }
      }
      int mn = min(twos , fives);      // get rid of trailing zeros
      twos -= mn;
      fives -= mn;
      lastdigit = mul(lastdigit , powMOD(2 , twos));
      lastdigit = mul(lastdigit , powMOD(5 , fives));
      cout << lastdigit << "\n";
   }
}