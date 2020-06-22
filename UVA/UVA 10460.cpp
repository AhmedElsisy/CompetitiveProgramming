/*
 * There is a mistake in the problem statement table (string of index 4) should be BAC
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
const long long MX = (long long)INT_MAX + 4;
long long mul(long long a , long long b){
   return min(a * b , MX);
}

long long add(long long a , long long b){
   return min(a + b , MX);
}

void solve() {
   string s;
   cin >> s;
   long long idx;
   cin >> idx;
   vector<long long> fact(30 , 1);
   for(int i = (int)s.size() ; i >= 0 ; --i){
      fact[i] = 1;
      for(int j = i ; j <= (int)s.size() ; ++j){
         fact[i] = mul(fact[i] , j);
      }
   }
   string rs = s.substr(0 , 1);
   for(int i = 1 ; i < (int)s.size() ; ++i){
      long long cr = 0 , lst = 0;
      for(int j = 0 ; j <= i ; ++j){
         cr = add(cr , fact[i + 2]);
         if(cr >= idx){
            idx -= lst;
            rs.insert(rs.begin() + j , s[i]);
            break;
         }
         lst = cr;
      }
   }
   cout << rs << "\n";
}

int main() {
#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
#endif
   ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
   int t = 1;
   cin >> t;
   while(t--){
      solve();
   }
}