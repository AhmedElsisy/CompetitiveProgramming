#include<iostream>
#include<cstring>
#include<iomanip>
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
const int N = 1e3 + 4 , M = 32;
int m , n , t , team;
double memo[M][M] , p[N][M] , calc[N][M] , sum[N][M];
double memo2[N][2];

double solve(int j , int remProblems){
   if(j == m)
      return (remProblems ? 0.0 : 1.0);
   double &ret = memo[j][remProblems];
   if(ret == ret)
      return ret;
   ret = 0.0;
   if(remProblems)ret += p[team][j] * solve(j + 1 , remProblems - 1);
   ret += (1 - p[team][j]) * solve(j + 1 , remProblems);
   return ret;
}

int curN;
double get(int i , bool champion){
   if(i == t)
      return (champion ? 1.0 : 0.0);
   double &ret = memo2[i][champion];
   if(ret == ret)
      return ret;
   ret = calc[i][curN] * get(i + 1 , true);
   ret += sum[i][curN - 1] * get(i + 1 , champion);   // was for each no. problems from 1 to curN - 1 , ret += calc[i][pro] * solve(i + 1 , champion)
   return ret;
}

int main() {
#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
#endif
   ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
   while (cin >> m >> t >> n) {
      if(!m && !t && !n)
         return 0;
      for (int i = 0; i < t; ++i) {
         for (int j = 0; j < m; ++j) {
            cin >> p[i][j];
         }
      }

      for (int i = 0; i < t; ++i) {
         memset(memo, -1, sizeof(memo));
         team = i;
         for (int j = 1; j <= m; ++j) {
            calc[i][j] = solve(0, j);
            sum[i][j] = sum[i][j - 1] + calc[i][j];
         }
      }

      double ans = 0.0;
      for (int i = n; i <= m; ++i) {
         curN = i;
         memset(memo2, -1, sizeof memo2);
         ans += get(0, 0);
      }
      cout << fixed << setprecision(3) << ans + EPS << "\n";
   }
}