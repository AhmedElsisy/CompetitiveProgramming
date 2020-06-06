/*
 * Timus - 1846	GCD 2010
 * gcd segment tree + compression
 * 0 as an identity element in gcd; gcd(x,0) = x
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
//template<typename T>
//using ordered_set =
//tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
typedef long long  ll;
#define EPS 1e-9
#define PI acos(-1.0)
const int N = 1e5 + 4;
int st[4*N] , cnt[N];
vector<int> uni;

int update(int p , int l , int r , int pos , int delta){
   if(l > pos || r < pos)
      return st[p];
   if(l == r){
      cnt[l] += delta;
      return st[p] = (cnt[l] ? uni[l] : 0);
   }
   int mid = (l + r) / 2;
   return st[p] = __gcd(update(p * 2 , l , mid , pos , delta) , update(p * 2 + 1 , mid + 1 , r , pos , delta));
}

void solve(){
   int n;
   cin >> n;
   vector<pair<char , int>> v(n);
   for(int i = 0 ; i < n ; ++i) {
      pair<char , int> &e = v[i];
      cin >> e.first >> e.second, uni.pb(e.second);
   }
   sort(all(uni));
   uni.resize(unique(all(uni)) - uni.begin());
   for(int i = 0 ; i < n ; ++i) {
      pair<char , int> &e = v[i];
      int delta = 1;
      if(e.first == '-')
         delta = -1;
      int idx = lower_bound(all(uni) , e.second) - uni.begin();
      update(1 , 0 , (int)uni.size() - 1 , idx , delta);
      cout << max(update(1 , 0 , (int)uni.size() - 1 , 0 , 0) , 1) << "\n";
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