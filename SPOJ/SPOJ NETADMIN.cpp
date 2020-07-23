// edmond karp will get TLE O(E^2*V) but Ford will get accepted because the flow is maximum k so O(k*dfscomplexity)
// binary search + maxflow
#include<bits/stdc++.h>
#define all(v) (v).begin() , (v).end()
#define popcnt(x) __builtin_popcount(x)
#define inf 0x3f3f3f3f
#define watch(x) cout << (#x) << " is " << (x) << endl
#define rand() (rand() << 15 | rand())
using namespace std;
typedef long long  ll;
#define EPS 1e-9
#define PI acos(-1.0)
const int N = 506;  // edit number of nodes here
struct Edge{
   int u , v , c;
};

vector<int> adj[N];
vector<Edge> edgeList;
int max_node , src , snk;

void init(){            // to be called every TESTCASE
   for(int i = 0 ; i <= max_node ; ++i)
      adj[i].clear();
   edgeList.clear();
}

void add_edge(int u , int v , int c){
   adj[u].push_back((int)edgeList.size());
   edgeList.push_back({u , v , c});
}

void add_biedge(int u , int v , int c){
   add_edge(u , v , c);
   add_edge(v , u , 0);
}

int vid = 1 , vis[N];
int dfs(int u , int mn){
   if(u == snk)
      return mn;
   vis[u] = vid;
   for(int child : adj[u]){
      int v = edgeList[child].v , c = edgeList[child].c;
      if(vis[v] == vid || !c)continue;
      int ret = dfs(v , min(mn , c));
      edgeList[child].c -= ret;
      edgeList[child ^ 1].c += ret;
      if(ret)return ret;          // found path return
   }
   return 0;
}

int FordFulkerson(){
   int mf = 0;
   while(1){
      vid++;
      int f = dfs(src , 1e9);
      if(!f)break;    // no flow
      mf += f;
   }
   return mf;
}

int main() {
#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
#endif
   ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
   int t;
   cin >> t;
   while(t--){
      int n , m , k;
      cin >> n >> m >> k;
      src = 1 , snk = n + 1 , max_node = snk + 2;
      init();
      vector<int> s(k);
      for(int &x : s)cin >> x , add_biedge(x , snk , 1);
      int j = (int)edgeList.size();
      for(int i = 0 ; i < m ; ++i){
         int u , v;
         cin >> u >> v;
         add_biedge(u , v , 0);
         add_biedge(v , u , 0);
      }

      int l = 0 , r = k , rs = k;
      while(l <= r) {
         int mid = (l + r) / 2;
         for (int i = 0; i < j; i += 2){
            edgeList[i].c = 1;
            edgeList[i+1].c = 0;
         }
         for(int i = j ; i < (int)edgeList.size() ; i += 2){
            edgeList[i].c = mid;
            edgeList[i+1].c = 0;
         }
         if(FordFulkerson() == k)
            rs = mid , r = mid - 1;
         else l = mid + 1;
      }
      cout << rs << "\n";
   }

}