/**
 *      link:   https://codeforces.com/contest/721/problem/C
 *
 *      - key idea of this problem to ignore constraint T for some period of thinking
 *      so for fixed number of nodes you can visit along the path between 1 to n you need to compute
 *      the minimum distance to visit this number of nodes, then you have to check whether the minimum distance <= T or not.
 *      using dp + print path you can do that stuff easily
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
const int N = 5004;
vector<pair<int , int>> adj[N];
long long memo[N][N];
int n , m , T;

long long solve(int u , int rem){
   if(u == n){
      return (!rem ? 0 : LLONG_MAX / 2);
   }
   long long &ret = memo[u][rem];
   if(~ret)
      return ret;
   ret = LLONG_MAX / 2;
   if(rem) {
      for (auto c : adj[u]) {
         ret = min(ret , c.second + solve(c.first , rem - 1));
      }
   }
   return ret;
}

void printPath(int u , int rem){
   cout << u << ' ';
   if(u == n){
      return;
   }
   if(rem){
      long long mn = LLONG_MAX / 2;
      int theOne = -1;
      for(auto c : adj[u]){
         if(c.second + solve(c.first , rem - 1) < mn){
            mn = c.second + solve(c.first , rem - 1);
            theOne = c.first;
         }
      }
      printPath(theOne , rem - 1);
   }
}
int main() {
#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
#endif
   ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
   cin >> n >> m >> T;
   for(int i = 0 ; i < m ; ++i){
      int u , v , c;
      cin >> u >> v >> c;
      adj[u].pb({v , c});
   }

   memset(memo , -1 , sizeof(memo));
   int i = n;
   for(i = n ; i >= 2 ; --i){
      long long res = solve(1 , i - 1);
      if(res <= T){
         break;
      }
   }
   cout << i << "\n";
   printPath(1 , i - 1);
   cout << "\n";

}