/**
 * maximum bipartite matching + floyd trasitive closure
 */
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

const int N = 504;  // edit number of nodes here
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

void init(){        // FOR EVERY TESTCASE you should call init()
   for(int i = 0 ; i <= max_node ; ++i)
      adj[i].clear();
   edgeList.clear();
}
// you need to initialize three variable -> (src , snk , max_node)
// call biedge(u , v , cost)

const int MAXN = 404;
bool mat[MAXN][MAXN];

vector<string> fix(vector<string> &v){
   vector<string> ret(all(v));
   sort(ret.begin() , ret.end());
   ret.resize(unique(ret.begin() , ret.end()) - ret.begin());
   return ret;
}
int main() {
#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
#endif
   ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
   int t;
   cin >> t;
   while (t--){
      init();
      memset(mat , false , sizeof(mat));
      int input;
      cin >> input;
      vector<string> IN(input);
      int cur_indx = 1;
      map<string, int> maping , cntin;
      for(int i = 0 ; i < input ; ++i){
         cin >> IN[i];
         if(!maping.count(IN[i])){
            maping[IN[i]] = cur_indx++;
         }
         cntin[IN[i]]++;
      }

      int output;
      cin >> output;
      vector<string> OUT(output);
      map<string, int> cntout;
      for(int i = 0 ; i < output ; ++i){
         string str;
         cin >> str >> OUT[i];
         if(!maping.count(OUT[i])){
            maping[OUT[i]] = cur_indx++;
         }
         cntout[OUT[i]]++;
      }

      int con;
      cin >> con;
      for(int i = 0 ; i < con ; ++i){
         string a , b;
         cin >> a >> b;
         if(!maping.count(a)){
            maping[a] = cur_indx++;
         }
         if(!maping.count(b)){
            maping[b] = cur_indx++;
         }

         int u = maping[a] , v = maping[b];
         mat[u][v] = true;
      }

      for(int i = 0 ; i < cur_indx ; ++i)
         mat[i][i] = true;
      for(int k = 0 ; k < cur_indx ; ++k){
         for(int i = 0 ; i < cur_indx ; ++i){
            for(int j = 0 ; j < cur_indx ; ++j){
               mat[i][j] |= (mat[i][k] && mat[k][j]);
            }
         }
      }

      src = 0;
      snk = cur_indx + input;
      max_node = snk + 2;
      IN = fix(IN);
      OUT = fix(OUT);
      for(int i = 0 ; i < IN.size() ; ++i){
         add_biedge(maping[IN[i]] , snk , cntin[IN[i]]);
//         cout << maping[IN[i]] << ' ' << snk << ' ' << cntin[IN[i]] << "\n";
      }
//      cout << "---------------\n";
      for(int i = 0 ; i < OUT.size() ; ++i){
         add_biedge(src , maping[OUT[i]] + input , cntout[OUT[i]]);
//         cout << src << ' ' << maping[OUT[i]] + input << ' ' << cntout[OUT[i]] << endl;
      }
//      cout << "---------------\n";
      for(int i = 0 ; i < IN.size() ; ++i){
         for(int j = 0 ; j < OUT.size() ; ++j){
            // out -> in
            if(mat[maping[OUT[j]]][maping[IN[i]]]){
//               cout << maping[OUT[j]] + input << ' ' << maping[IN[i]] << endl;
               add_biedge(maping[OUT[j]] + input , maping[IN[i]] , inf);
            }
         }
      }
      cout << output - EdmondKarp() << "\n";
      if(t)
         cout << "\n";
   }
}