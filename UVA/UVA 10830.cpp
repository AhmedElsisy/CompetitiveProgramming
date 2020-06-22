/*
 * UVA 10830
 * check this: https://github.com/mostafa-saad/MyCompetitiveProgramming/blob/master/UVA/UVA_10830.txt#L17
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
long long sum(long long x , long long y){
   long long sz = y - x + 1;
   return ((x + y) * sz) / 2;
}
int main() {
#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
#endif
   ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
   int n , cs = 1;
   while(cin >> n && n){
      long long rs = 0;
      vector<long long> a;
      long long sq = 1;
      for(long long i = 2 ; 1ll * i * i <= n ; ++i){
         long long times = (n / i) - 1;
         rs += i * times;
         a.push_back(n / (n / i));
         sq = i;
      }
      if((int)a.size()) {
         long long lst = n / a[0];
         for (int i = 1; i < (int) a.size(); ++i) {
            long long sm = sum(n / a[i] + 1 , lst);
            rs += 1ll * sm * (a[i - 1] - 1);
            lst = n / a[i];
         }
         rs += sum(sq + 1 , lst) * (a.back() - 1);
      }
      cout << "Case " << cs++ << ": " << rs << "\n";
   }
}