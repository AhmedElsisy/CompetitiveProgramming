#include<bits/stdc++.h>
#define pb push_back
#define all(v) (v).begin() , (v).end()
#define popcnt(x) __builtin_popcount(x)
#define inf 0x3f3f3f3f
#define watch(x) cout << (#x) << " is " << (x) << endl
#define rand() (rand() << 15 | rand())
using namespace std;
typedef long long  ll;
const int N = 240;  // edit number of nodes here
struct Edge{
   int u , v , c;
};

vector<int> adj[N] , par , to;
vector<Edge> edgeList;
int max_node , src , snk;

void init(){        // FOR EVERY TESTCASE you should call init()
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

int augment(int u , int mn){
   if(par[u] == -1){
      return (u == src ? mn : 0);
   }
   int ret = augment(par[u] , min(mn , edgeList[to[u]].c));
   edgeList[to[u]].c -= ret;
   edgeList[to[u] ^ 1].c += ret;
   return ret;
}

int EdmondKarp(){
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

// you need to initialize three variable -> (src , snk , max_node)
// call biedge(u , v , cost)
double getDist(int x0 , int y0 , int x1 , int y1){
   int dx = x0 - x1 , dy = y0 - y1;
   return sqrt(dx * dx + dy * dy);
}
const double EPS = 1e-9;
int x[N] , y[N] , cnt[N] , cap[N] , in[N] , out[N];
int main() {
#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
#endif
   ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
   int T;
   cin >> T;
   while (T--){
      int n;
      double Jmp;
      cin >> n >> Jmp;
      int sum = 0;
      for(int i = 0 ; i < n ; ++i){
         cin >> x[i] >> y[i] >> cnt[i] >> cap[i];
         sum += cnt[i];
         in[i] = 2 * i , out[i] = 2 * i + 1;
      }
      vector<int> res;
      for(int i = 0 ; i < n ; ++i){
         // build new graph
         init();
         src = 2 * n + 1 , snk = in[i] , max_node = 2 * n + 2;
         for(int j = 0 ; j < n ; ++j){
            for(int k = 0 ; k < n ; ++k){
               if(j == k)continue;
               double d = getDist(x[j] , y[j] , x[k] , y[k]);
               if(d < Jmp + EPS){
                  add_biedge(out[j] , in[k] , inf);
               }
            }
         }

         for(int j = 0 ; j < n ; ++j){
            add_biedge(in[j] , out[j] , cap[j]);
            if(cnt[j])add_biedge(src , in[j] , cnt[j]);
         }
         // run MAXFLOW
         int f = EdmondKarp();
         // update the answer
         if(f == sum)res.pb(i);
      }

      if(res.empty())cout << "-1\n";
      else {
         cout << res[0];
         for(int i = 1 ; i < (int)res.size() ; ++i){
            cout << ' ' << res[i];
         }
         cout << "\n";
      }
   }
}