/*
 * you should track min and max because if a[i] < 0 then you can maximize by multiplying by negative number
 * editorial:https://www.topcoder.com/thrive/articles/SRM%20453.5
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
#define PI acos(-1.0)
const int N = 55;
pair<long long , long long> memo[N][11];
int n , a[N] , d;
bool vis[N][11];
pair<long long , long long> solve(int i , int k){
   if(!k)
      return {1 , 1};
   pair<long long , long long> &ret = memo[i][k];
   if(vis[i][k])
      return ret;
   vis[i][k] = true;
   ret = {LLONG_MIN , LLONG_MAX};
   for(int j = 1 ; n - (i + j) >= k - 1 && i + j <= n && j <= d ; ++j){
      auto cr = solve(i + j , k - 1);
      if(a[i] >= 0)ret.first = max(ret.first , 1LL * a[i] * cr.first) , ret.second = min(ret.second , 1LL * a[i] * cr.second);
      else ret.first = max(ret.first , 1LL * a[i] * cr.second) , ret.second = min(ret.second , 1LL * a[i] * cr.first);
   }
   return ret;
}
class TheProduct{
public:
   long long maxProduct(vector<int> numbers, int k, int maxDist){
      n = (int)numbers.size();
      for(int i = 0 ; i < n ; ++i)a[i] = numbers[i];
      d = maxDist;
      memset(vis , 0 , sizeof(vis));
      long long rs = LLONG_MIN;
      for(int i = 0 ; i < n && n - i >= k ; ++i)
         rs = max(rs , solve(i , k).first);
      return rs;
   }
};