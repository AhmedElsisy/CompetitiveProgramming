#include<bits/stdc++.h>
#define pb push_back
#define all(v) (v).begin() , (v).end()
#define popcnt(x) __builtin_popcount(x)
//#define inf 0x3f3f3f3f
#define inf 100001
#define watch(x) cout << (#x) << " is " << (x) << endl
#define rand() (rand() << 15 | rand())
using namespace std;
typedef long long  ll;
#define EPS 1e-9
#define PI acos(-1.0)
const int N = 55;
bool mat[N][N] , CCmat[N][N];
int in[N] , n , cnt = -1 , minCost[N] , cmp[N];

void init(){
   cnt = -1;
   memset(cmp , -1 , sizeof(cmp));
   memset(mat , false , sizeof(mat));
   memset(in , 0 , sizeof(in));
   memset(CCmat , false , sizeof(CCmat));
}
void build(vector<int> &c){
   for(int i = 0 ; i < n ; ++i)
      mat[i][i] = true;
   for(int k = 0 ; k < n ; ++k){
      for(int i = 0 ; i < n ; ++i){
         for(int j = 0 ; j < n ; ++j){
            mat[i][j] |= (mat[i][k] && mat[k][j]);
         }
      }
   }

   for(int i = 0 ; i < n ; ++i){
      if(cmp[i] == -1){
         cmp[i] = ++cnt;
         minCost[cnt] = i;
         for(int j = 0 ; j < n ; ++j){
            if(mat[i][j] && mat[j][i]){
               cmp[j] = cnt;
               if(c[minCost[cnt]] > c[j])minCost[cnt] = j;
            }
         }
      }
   }

   for(int i = 0 ; i < n ; ++i){
      for(int j = 0 ; j < n ; ++j){
         if(mat[i][j])
            CCmat[cmp[i]][cmp[j]] = true , in[cmp[j]] += (cmp[i] != cmp[j]);
      }
   }
}

class AntarcticaPolice{
public:
   double minAverageCost(vector<int> costs, vector<string> roads){
      n = (int)costs.size();
      init();
      for(int i = 0 ; i < n ; ++i){
         for(int j = 0 ; j < n ; ++j){
            if(roads[i][j] == 'Y')
               mat[i][j] = true;
         }
      }
      build(costs);
      vector<bool> vis(n , false);
      int sum = 0 , sz = 0;
      for(int i = 0 ; i <= cnt ; ++i){
         if(!in[i])sum += costs[minCost[i]] , sz++ , vis[minCost[i]] = true;
      }
      priority_queue<int , vector<int> , greater<int>> pq;
      for(int i = 0 ; i < n ; ++i){
         if(!vis[i]){
            pq.push(costs[i]);
         }
      }
      while (pq.size() && pq.top() * sz <= sum){
         sum += pq.top();
         pq.pop();
         sz++;
      }
      return 1.0 * sum / sz;
   }
};