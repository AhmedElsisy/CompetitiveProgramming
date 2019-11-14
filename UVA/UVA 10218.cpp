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
const int N = 1e3 + 4 , M = 1e2 + 3;

// one person can take more than one candy so the probability of give man is (men) / (men + women)
double memo[M][M];
int men , women , C;
double solve(int remM , int remC){
   if(!remC){
      return (remM % 2 == 0 ? 1.0 : 0.0);
   }
   double &ret = memo[remM][remC];
   if(ret == ret)
      return ret;
   ret = 0.0;
   ret += (1.0 * men / (men + women)) * solve(remM + 1  , remC - 1);
   ret += (1.0 * women / (men + women)) * solve(remM , remC - 1);
   return ret;
}
int main() {
#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
#endif
   ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
   while (cin >> men >> women >> C){
      if(!men && !women)
         return 0;
      memset(memo , -1 , sizeof(memo));
      cout << fixed << setprecision(7) << solve(0 , C) + EPS << "\n";
   }
}