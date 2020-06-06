/**
 * dp + datastructure (segment tree)
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
const int N = 1e4 + 4;
int st[2][4 * N];

int update(int p , int e , int l , int r , int pos , int v) {
   if (pos < l || pos > r)
      return st[e][p];
   if (l == r)
      return st[e][p] = v;
   int mid = (l + r) / 2;
   return st[e][p] = max(update(p * 2, e, l, mid, pos, v), update(p * 2 + 1, e, mid + 1, r, pos, v));
}

int query(int p , int e , int l , int r , int i , int j) {
   if (l > j || r < i)
      return 0;
   if (l >= i && r <= j)
      return st[e][p];
   int mid = (l + r) / 2;
   return max(query(p * 2, e, l, mid, i, j), query(p * 2 + 1, e, mid + 1, r, i, j));
}

void solve() {
   int n;
   while(cin >> n) {
      map<int, vector<int>> mp;
      for (int i = 0; i < n; ++i) {
         int x;
         cin >> x;
         mp[x].pb(i);
      }

      int rs = 0;
      vector<array<int , 2>> upd( n + 1);
      for (auto &e : mp) {
         int x = e.first;
         for (int pos : e.second) {
            int l = (pos ? query(1, 0, 0, n - 1, 0, pos - 1) : 0);
            int r = (pos + 1 < n ? query(1, 1, 0, n - 1, pos + 1, n - 1) : 0);
            rs = max(rs, min(l, r) * 2 + 1);
            upd[pos] = {l , r};
         }
         for (int pos : e.second) {
            update(1, 0, 0, n - 1, pos, upd[pos][0] + 1);
            update(1, 1, 0, n - 1, pos, upd[pos][1] + 1);
         }
      }
      cout << rs << "\n";
      for(int i = 0 ; i < n ; ++i)
         for(int j = 0 ; j < 2 ; ++j)
            update(1 , j , 0 , n - 1 , i , 0);
   }
}

int main() {
#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
#endif
   ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
   int t = 1;
//   cin >> t;
   while(t--){
      solve();
   }
}