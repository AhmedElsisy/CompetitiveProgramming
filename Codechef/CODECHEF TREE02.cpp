#include<bits/stdc++.h>
#define pb push_back
#define all(v) (v).begin() , (v).end()
#define popcnt(x) __builtin_popcount(x)
#define inf 0x3f3f3f3f
#define watch(x) cout << (#x) << " is " << (x) << endl
#define rand() (rand() << 15 | rand())
using namespace std;
typedef long long  ll;
#define EPS 1e-9
#define PI acos(-1.0)
const int N = 2e4 + 4;
vector<int> adj[N];
int w[N] , n , k , cnt = 0;
ll mx , sum[N];
vector<ll> tmp;
/**
    partitioning the tree into k subtree greedily using binary search
 */
void dfs(int u , int p){
   sum[u] = w[u];
   for(int c : adj[u]){
      if(c == p)continue;
      dfs(c , u);
   }
   tmp.clear();
   for(int c : adj[u]){
      if(c == p)continue;
      tmp.pb(sum[c]);
   }
   sort(all(tmp));
   for(int i = 0 ; i < (int)tmp.size() ; ++i){
      if(sum[u] + tmp[i] <= mx)
         sum[u] += tmp[i];
      else {
         cnt += (int)tmp.size() - i;
         break;
      }
   }
}

bool valid(ll mid){
   mx = mid;
   cnt = 0;
   dfs(1 , 1);
   return cnt < k;
}

int main() {
#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
#endif
   ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
   cin >> n >> k;
   for(int i = 1 ; i <= n ; ++i)
      cin >> w[i];
   for(int i = 0 ; i + 1 < n ; ++i){
      int u , v;
      cin >> u >> v;
      adj[u].pb(v);
      adj[v].pb(u);
   }

   ll l =  *max_element(w + 1 , w + n + 1) , r = 1000000000ll * N , ans = -1;
   while(l <= r){
      ll mid = l + (r - l) / 2;
      if(valid(mid)){
         ans = mid;
         r = mid - 1;
      }
      else l = mid + 1;
   }

   cout << ans << "\n";
}