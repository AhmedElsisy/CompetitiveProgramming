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
const int SQRT = 550 , N = 3e5 + 4;
ll a[N] , u;
vector<ll> b[SQRT];

int main() {
#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
#endif
   ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
   int n , q;
   while(cin >> n >> q >> u) {
      for (int i = 0; i < SQRT; ++i)
         b[i].clear();
      for (int i = 0; i < n; ++i) {
         cin >> a[i];
         b[i / SQRT].pb(a[i]);
      }
      for (int i = 0; i < SQRT; ++i)
         sort(all(b[i]));

      while (q--) {
         int l, r, v, p;
         cin >> l >> r >> v >> p;
         l--, r--, p--;
         int cl = l / SQRT, cr = r / SQRT, k = 0;
         if (cl == cr) {
            for (int i = l; i <= r; ++i)
               k += (a[i] < v);
         } else {
            for (int i = l; i < (cl + 1) * SQRT; ++i)
               k += (a[i] < v);
            for (int i = cl + 1; i < cr; ++i)
               k += lower_bound(all(b[i]), v) - b[i].begin();
            for (int i = cr * SQRT; i <= r; ++i)
               k += (a[i] < v);
         }
         int block = p / SQRT, pos = p % SQRT;
         a[p] = (u * k) / (r - l + 1);
         b[block][pos] = a[p];
         //      for(int i = 0 ; i < b[block].size() ; ++i){
         //         cout << b[block][i] << ' ';
         //      }
//         cout << "\n";
         for (int i = pos; i + 1 < b[block].size(); ++i) {
            if (b[block][i] > b[block][i + 1])
               swap(b[block][i], b[block][i + 1]);
         }

         for (int i = pos; i > 0; --i) {
            if (b[block][i] < b[block][i - 1])
               swap(b[block][i], b[block][i - 1]);
         }
         //      for(int i = 0 ; i < b[block].size() ; ++i){
         //         cout << b[block][i] << ' ';
         //      }
         //      cout << "\n";
      }

      for (int i = 0; i < n; ++i)
         cout << a[i] << '\n';
   }
}