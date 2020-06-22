/*
 * for each pair of points search for all valid third point using the fact of dot product of two vectors
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
#define x first
#define y second
typedef pair<int, int> pt;
inline pt operator -(const pt &a, const pt &b) {
   return {a.x - b.x, a.y - b.y};
}

pt gt(pt vc){
   int l = abs(vc.x) , r = abs(vc.y);
   int gcd = __gcd(l , r);
   vc.x /= gcd , vc.y /= gcd;
   return vc;
}

int main() {
#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
#endif
   ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
   int n;
   cin >> n;
   vector<pt> v(n);
   for(int i = 0 ; i < n ; ++i)
      cin >> v[i].x >> v[i].y;

   map<pt , int> cnt;
   int rs = 0;
   for(int i = 0 ; i < n ; ++i){
      cnt.clear();
      for(int j = 0 ; j < n ; ++j)
         if(j != i)cnt[gt(v[j] - v[i])]++;
      for(int j = 0 ; j < n ; ++j){
         if(i == j)continue;
         pt vc = gt(v[j] - v[i]);
         swap(vc.x , vc.y);
         vc.y *= -1;
         rs += (cnt.count(vc) ? cnt[vc] : 0);
      }
   }
   cout << rs << "\n";
}
