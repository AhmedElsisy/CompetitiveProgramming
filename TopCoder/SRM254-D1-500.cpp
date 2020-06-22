/*
 * DP, try every possible valid state
 */
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define pb push_back
#define all(v) (v).begin() , (v).end()
#define popcnt(x) __builtin_popcount(x)
#define inf 0x3f3f3f3f
#define watch(x) cout << (#x) << " is " << (x) << endl
#define rand() (rand() << 15 | rand())
using namespace std;
using namespace __gnu_pbds;

template<typename T>
using ordered_set =
tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
typedef long long  ll;
#define EPS 1e-9
#define PI acos(-1.0)
const int N = 55;
string s1 , s2;
int memo[N][12][12];
int fx(int m){
   while(m < 0)
      m += 10;
   if(m >= 10)
      m -= 10;
   return m;
}
int solve(int idx , int nw , int nx){
   if(idx == s1.size())
      return 0;
   int &ret = memo[idx][nw][nx];
   if(~ret)
      return ret;
   ret = inf;
   int to = s2[idx] - '0' , cr = fx(s1[idx] - '0' + nw);
   for(int d = -9 ; d < 10 ; ++d){
      for(int e = -9 ; e < 10 ; ++e){
         for(int k = -9 ; k < 10 ; ++k){
            int cost = (abs(d) + 2) / 3 + (abs(e) + 2) / 3 + (abs(k) + 2) / 3;
            if(fx(cr + d + e + k) == to)
               ret = min(ret , cost + solve(idx + 1 , fx(nx + d + e) , fx(d)));
         }
      }
   }
   return ret;
}
// 156
// 623
class BikeLock{
public:
   int minTurns(string current, string desired){
      s1 = current , s2 = desired;
      memset(memo , -1 , sizeof(memo));
      return solve(0 , 0 , 0);
   }
};