/**
 * Resources:
 *      https://stackoverflow.com/questions/25281005/calculating-probability-for-funprob
 *      http://www.geometer.org/mathcircles/catalan.pdf
 *      https://www.youtube.com/watch?v=GlI17WaMrtw&t=3s
 *
 * Solving this problems using CATALAN NUMBERS
 * Assume 2D plane x axis is number of persons will pay 5$ and y axis is number of persons will pay 10$
 * So you want to know in how many way you can reach point (m , n) without crossing the main diagonal (1,1) (2,2) (3,3) ... (inf,inf)
 * because crossing the main diagonal means number of persons paid 10$ is more than number of persons paid 5$ so you can't give them the change
 * this can be solved using Catalan numbers (check the resources)
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

int main() {
#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
#endif
   ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
   ll n , m;
   while (cin >> n >> m){
      if(!n && !m)
         return 0;
      if(n > m){
         cout << fixed << setprecision(6) << 0.0 << "\n";
         continue;
      }
      double res = 1.0 * (m - n + 1) / (m + 1);
      cout << fixed << setprecision(6) << res << "\n";
   }
}