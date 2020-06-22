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
#define PI acos(-1.0)

struct point {
   int x, y;   // only used if more precision is needed
   point() { x = y = 0.0; }                      // default constructor
   point(int _x, int _y) : x(_x), y(_y) {}        // user-defined
};

long long latticePoints(point a, point b) { // returns number of lattice points on segment ab
   long long dx = abs(b.x - a.x) , dy = abs(b.y - a.y);
   return __gcd(dx , dy) + 1;
}

// returns the 2*area (for integer stuff)
long long area_doubled(const vector<point> &P) {
   long long result = 0.0, x1, y1, x2, y2;
   for (int i = 0; i < (int) P.size() - 1; i++) {
      x1 = P[i].x;
      x2 = P[i + 1].x;
      y1 = P[i].y;
      y2 = P[i + 1].y;
      result += (x1 * y2 - x2 * y1);
   }
   return abs(result);
}

long long picksTheorm(const vector<point> &P){  // I = (2*A - B + 2) / 2
   long long A = area_doubled(P);
   long long B = (int)P.size() - 1;
   for(int i = 0 ; i + 1 < P.size() ; ++i){
      B += latticePoints(P[i] , P[i + 1]) - 2; // to avoid over counting polygon vertices
   }
   return (A - B + 2) / 2;
}

int main() {
#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
#endif
   ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
   int n;
   while(cin >> n && n){
      vector<point> P(n);
      for(int i = 0 ; i < n ; ++i){
         cin >> P[i].x >> P[i].y;
      }
      P.push_back(P[0]);
      cout << picksTheorm(P) << "\n";
   }
}