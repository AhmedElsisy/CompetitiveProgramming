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
ll memo[52][52];
ll nCr(int n , int r){
   if(n < r)
      return 0;
   if(n == r)
      return 1;
   if(!r)
      return 1;
   ll &ret = memo[n][r];
   if(~ret)
      return ret;
   return ret = nCr(n - 1 , r - 1) + nCr(n - 1 , r);
}
const int N = 52;

// iterate over all possible maximum of queue for each one calculate what is the probability of its happen
double memo2[N][N][2];
int n , m , mx = -1 , a[N];
double solve(int idx , int remst , bool f){
   if(idx == m)
      return (!remst && f ? 1.0 : 0.0);
   double &ret = memo2[idx][remst][f];
   if(ret == ret)
      return ret;
   ret = 0.0;
   double p = 1.0 / m;
   for(int i = 0 ; i <= remst && ((i + a[idx] - 1) / a[idx]) <= mx ; ++i){
      ret += nCr(remst , i) * pow(p , i) * solve(idx + 1 , remst - i , f || (((i + a[idx] - 1) / a[idx]) == mx)); // i students will choose this room so remst C i possible way to do this
   }
   return ret;
}
int main() {
#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
#endif
   ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
   cin >> n >> m;
   for(int i = 0 ; i < m ; ++i)
      cin >> a[i];
   memset(memo , -1 , sizeof(memo));
   double res = 0.0;
   for(int i = 1 ; i <= n ; ++i){
      mx = i;
      memset(memo2 , -1 , sizeof memo2);
      res += i * solve(0 , n , false);
   }
   cout << fixed << setprecision(10) << res << "\n";
}