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
const int N = 100 + 4;
vector<int> adj[N] , match , vis;
int n , vid = 1;

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

int MCBM(){
   match.assign(n , -1);
   vis.assign(n , 0);
   int ret = 0;
   for(int i = 0 ; i < n ; ++i){    // 1 - based
      if(dfs(i))++ret;
      ++vid;
   }
   return ret;
}


class PeopleYouMayKnow{
public:
   int maximalScore(vector <string> friends, int person1, int person2){
      n = friends.size();
      int ret = 0;
      vector<bool> r1(n , false) , r2(n , false);
      for(int i = 0 ; i < n ; ++i){
         if(i == person1 || i == person2)continue;
         if(friends[person1][i] == 'Y')r1[i] = true;
         if(friends[person2][i] == 'Y')r2[i] = true;
      }
      for(int i = 0 ; i < n ; ++i){
         if(r1[i] && r2[i])
            ret++ , r1[i] = r2[i] = false;
      }
      for(int i = 0 ; i < n ; ++i){
         for(int j = 0 ; j < n ; ++j){
            if(r1[i] && r2[j] && friends[i][j] == 'Y'){
               adj[i].pb(j);
            }
         }
      }
      ret += MCBM();
      return ret;
   }
};