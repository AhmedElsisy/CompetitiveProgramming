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
const int N = 1e4 + 4;
int a[N] , cnt[N];
long long ways[N];
vector<int> divs[N];
long long nC4(int n){
   long long rt = 1ll * n * (n - 1) * (n - 2) * (n - 3);
   return rt / 24;
}
int main() {
#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
#endif
   ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

   for(int i = 1 ; i < N ; ++i){
      for(int j = i ; j < N ; j += i)
         divs[j].pb(i);
   }
   int n;
   while(cin >> n){
      for(int i = 0 ; i < n ; ++i) {
         int &x = a[i];
         cin >> x;
         for(int d : divs[x])
            cnt[d]++;
      }
      for(int i = 10000 ; i > 0 ; --i){
         ways[i] = nC4(cnt[i]);
         for(int j = 2 * i ; j < N ; j += i)
            ways[i] -= ways[j];
         cnt[i] = 0;
      }
      cout << ways[1] << "\n";
   }
}