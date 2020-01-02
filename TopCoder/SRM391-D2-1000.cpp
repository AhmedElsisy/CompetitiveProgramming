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
const int N = 405;
bool mat[N][N] , CCmat[N][N];
int n , cnt = -1 , cmp[N] , val[N] , CCval[N];

void init(){
   cnt = -1;
   memset(cmp , -1 , sizeof(cmp));
   memset(mat , false , sizeof(mat));
   memset(CCmat , false , sizeof(CCmat));
}

void build(){
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
         for(int j = 0 ; j < n ; ++j){
            if(mat[i][j] && mat[j][i]){
               cmp[j] = cnt;
               CCval[cnt] += val[j];
            }
         }
      }
   }

   for(int i = 0 ; i < n ; ++i){
      for(int j = 0 ; j < n ; ++j){
         if(mat[i][j])
            CCmat[cmp[i]][cmp[j]] = true;
      }
   }
}


int gridN , gridM;
int getID(int i , int j){
   return i * gridM + j;
}

bool valid(int i , int j , vector<string> &g){
   if(i < 0 || i >= gridN || j < 0 || j >= gridM || g[i][j] == '#')
      return false;
   return true;
}

int memo[N];
int solve(int i){
   int &ret = memo[i];
   if(~ret)
      return ret;
   ret = CCval[i];
   for(int j = 0 ; j <= cnt ; ++j){
      if(CCmat[i][j] && i != j)
         ret = max(ret , CCval[i] + solve(j));
   }
   return ret;
}

class MarbleCollectionGame{
public:
   int collectMarble(vector<string> board){
      gridN = board.size() , gridM = board[0].size();
      init();
      for(int i = 0 ; i < gridN ; ++i){
         for(int j = 0 ; j < gridM ; ++j){
            int nodeID = getID(i , j);
            if(board[i][j] == 'L'){
               if(valid(i , j - 1 , board))mat[nodeID][getID(i , j - 1)] = true;
               if(valid(i + 1 , j , board))mat[nodeID][getID(i + 1 , j)] = true;
               if(valid(i , j + 1 , board))mat[nodeID][getID(i , j + 1)] = true;
            }
            else if(board[i][j] == 'U'){
               if(valid(i - 1, j  , board))mat[nodeID][getID(i - 1 , j)] = true;
               if(valid(i + 1 , j , board))mat[nodeID][getID(i + 1 , j)] = true;
               if(valid(i , j + 1 , board))mat[nodeID][getID(i , j + 1)] = true;
            }
            else if(board[i][j] == '#'){
               continue;
            }
            else{
               val[nodeID] = board[i][j] - '0';
               if(valid(i + 1 , j , board))mat[nodeID][getID(i + 1 , j)] = true;
               if(valid(i , j + 1 , board))mat[nodeID][getID(i , j + 1)] = true;
            }
         }
      }

      n = gridN * gridM;
      build();
      memset(memo , -1 , sizeof(memo));
      return solve(cmp[0]);
   }
};

int main() {
#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
#endif
   ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
   MarbleCollectionGame ob;
   cout << ob.collectMarble({"039LLLU",
                             "953348#",
                             "0L87#29",
                             "718#4#U",
                             "594U196"}

   ) << "\n";
}