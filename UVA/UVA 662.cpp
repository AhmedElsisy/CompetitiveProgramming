/**
 * dp + printpath
 */

#include<bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define all(v) (v).begin() , (v).end()
#define popcnt(x) __builtin_popcount(x)
#define inf 0x3f3f3f3f
#define watch(x) cout << (#x) << " is " << (x) << endl
#define rand() (rand() << 15 | rand())
using namespace std;
//using namespace __gnu_pbds;
//
//template<typename T>
//using ordered_set =
//tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
typedef long long  ll;
#define EPS 1e-9
#define PI acos(-1.0)
const int N = 204 , M = 33;
int n , k;
long long memo[N][M] , c[N] , d[N];
long long gt(int i , int j){
   return c[j] - c[i - 1];
}
long long solve(int i , int rm){
   if(i == n + 1)
      return 0;
   if(!rm)
      return LLONG_MAX / 2;
   long long &ret = memo[i][rm];
   if(~ret)
      return ret;
   ret = LLONG_MAX / 2;
   for(int j = i ; j <= n ; ++j){
      int mid = (i + j) / 2;
      // i -> mid , mid + 1 -> r
      long long cost = 1ll * (mid - i + 1) * d[mid] - gt(i , mid);
      if(mid + 1 <= j)
         cost += gt(mid + 1 , j) - 1ll * (j - mid) * d[mid];
      ret = min(ret , cost + solve(j + 1 , rm - 1));
   }
   return ret;
}

void pr(int i , int rm , int idx){
   if(i == n + 1)
      return;

   int r;
   long long best = LLONG_MAX / 2;
   for(int j = i ; j <= n ; ++j){
      int mid = (i + j) / 2;
      // i -> mid , mid + 1 -> r
      long long cost = 1ll * (mid - i + 1) * d[mid] - gt(i , mid);
      if(mid + 1 <= j)
         cost += gt(mid + 1 , j) - 1ll * (j - mid) * d[mid];
      if(best > cost + solve(j + 1 , rm - 1)){
         best = cost + solve(j + 1 , rm - 1);
         r = j;
      }
   }
// Depot 1 at restaurant 2 serves restaurants 1 to 3
   if(r != i)cout << "Depot " << idx << " at restaurant " << (i + r) / 2 << " serves restaurants " << i << " to " << r << "\n";
   else cout << "Depot " << idx << " at restaurant " << (i + r) / 2 << " serves restaurant " << i << "\n";
   pr(r + 1 , rm - 1 , idx + 1);
}
int cs = 1;
void solve() {
   cin >> n >> k;
   if(!n && !k)
      exit(0);
   for(int i = 1 ; i <= n ; ++i){
      cin >> d[i];
      c[i] = d[i] + c[i - 1];
   }
   memset(memo , -1 , sizeof(memo));

   cout << "Chain " << cs++ << "\n";
   pr(1 , k , 1);
   cout << "Total distance sum = " << solve(1 , k) << "\n\n";
}

int main() {
#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
#endif
   ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
   int t = 1;
//   cin >> t;
   while(t){
      solve();
   }
}