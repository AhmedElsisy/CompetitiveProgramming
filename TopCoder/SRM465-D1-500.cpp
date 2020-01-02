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
const int MOD = 1e9 + 7;

const int N = 204;  // edit number of nodes here
struct Edge{
   int u , v , c;
};

vector<int> adj[N] , par , to;
vector<Edge> edgeList;
int max_node , src , snk;

void add_edge(int u , int v , int c){
   adj[u].push_back((int)edgeList.size());
   edgeList.push_back({u , v , c});
}

void add_biedge(int u , int v , int c){
   add_edge(u , v , c);
   add_edge(v , u , 0);
}

int augment(int u , int mn){
   if(par[u] == -1){
      return (u == src ? mn : 0);
   }
   int ret = augment(par[u] , min(mn , edgeList[to[u]].c));
   edgeList[to[u]].c -= ret;
   edgeList[to[u] ^ 1].c += ret;
   return ret;
}

int EdmondKarp(){       // O(V . E^2)
   int mf = 0;
   while(1){
      par.assign(max_node + 1 , -1);
      to.assign(max_node + 1 , -1);
      queue<int> q;
      q.push(src);
      while(!q.empty()){
         int top = q.front();
         q.pop();
         if(top == snk)break;
         for(int child : adj[top]){
            int u = top , v = edgeList[child].v , c = edgeList[child].c;
            if(par[v] != -1 || !c || v == src)continue;
            par[v] = u;
            to[v] = child;      // indx of the edge in edgeList
            q.push(v);
         }
      }
      int f = augment(snk , 1e9);
      if(!f)break;      // means no path
      mf += f;
   }
   return mf;
}

void init(){        // FOR EVERY TESTCASE you should call init()
   for(int i = 0 ; i <= max_node ; ++i)
      adj[i].clear();
   edgeList.clear();
}
// you need to initialize three variable -> (src , snk , max_node)
// it's directed edge add_biedge(u , v , c)
// call biedge(u , v , cost)

int dist(int x0 , int y0 , int x1 , int y1){
   int dx = x0 - x1 , dy = y0 - y1;
   return dx * dx + dy * dy;
}

class GreenWarfare{
public:
   int minimumEnergyCost(vector<int> canonX, vector<int> canonY, vector<int> baseX, vector<int> baseY, vector<int> plantX, vector<int> plantY, int energySupplyRadius){
      energySupplyRadius *= energySupplyRadius; // avoid double
      int n = canonX.size() , m = baseX.size() , k = plantX.size();
      src = 0;
      snk = m + k + 1;
      max_node = snk + 1;
      init();
      for(int i = 0 ; i < m ; ++i){
         int node = k + i + 1 , mnDist = inf;
         for(int j = 0 ; j < n ; ++j){
            mnDist = min(mnDist , dist(canonX[j] , canonY[j] , baseX[i] , baseY[i]));
         }
         add_biedge(node , snk , mnDist);
      }

      for(int i = 0 ; i < k ; ++i){
         int node = i + 1 , mnDist = inf;
         for(int j = 0 ; j < n ; ++j){
            mnDist = min(mnDist , dist(canonX[j] , canonY[j] , plantX[i] , plantY[i]));
         }
         add_biedge(src , node , mnDist);
      }

      for(int i = 0 ; i < k ; ++i){
         int plant = i + 1;
         for(int j = 0 ; j < m ; ++j){
            int base = k + j + 1;
            if(dist(plantX[i] , plantY[i] , baseX[j] , baseY[j]) <= energySupplyRadius){
               add_biedge(plant , base , inf);
            }
         }
      }

      return EdmondKarp();
   }
};
