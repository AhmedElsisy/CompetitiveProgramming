/*
 * if we build a bipartite graph between N modes of Machine 1 and M modes of Machine 2
 * and the jobs as an edge between its x , y modes
 * then we need Minimum Vertex Cover all edges(jobs) with ignoring first mode(mode 0)
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
const int N = 100 + 4;
vector<int> adj[N] , match , vis;
int vid = 1 , leftSZ , rightSZ;

int dfs(int u){
   if(vis[u] == vid)
      return 0;
   vis[u] = vid;
   for(int v : adj[u]){
      if(match[v] == -1 || dfs(match[v])){
         match[v] = u;
         return 1;
      }
   }
   return 0;
}

int MCBM(){       // O(n^2)
   match.assign(rightSZ + 1 , -1);
   vis.assign(leftSZ + 1 , 0);
   int ret = 0;
   for(int i = 1 ; i <= leftSZ ; ++i){    // 1 - based
      if(dfs(i))++ret;
      ++vid;
   }
   return ret;
}

void init(int l , int r){
   leftSZ = l , rightSZ = r;
   for(int i = 0 ; i <= leftSZ ; ++i)
      adj[i].clear();
   match.clear();
   vis.clear();
}
int main() {
#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
#endif
   ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
   int n , m , k;
   while(cin >> n && n){
      init(n , m);
      vid = 1;
      cin >> m >> k;
      for(int i = 0 ; i < k ; ++i){
         int j , u , v;
         cin >> j >> u >> v;
         u++ , v++; // to 1-based
         if(u == 1 || v == 1) // ignore 0-mode
            continue;
         adj[u].pb(v);
      }
      cout << MCBM() << "\n";
   }
}
