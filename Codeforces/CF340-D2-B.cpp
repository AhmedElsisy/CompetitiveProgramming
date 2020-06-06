/**
 *      link: https://codeforces.com/contest/340/problem/B
 *      I got WA because I miss understand the problem I thought quadrilateral is only parallelogram
 *
 */
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

double DEG_to_RAD(double d) { return d * PI / 180.0; }
double RAD_to_DEG(double r) { return r * 180.0 / PI; }

struct point { double x, y;   // only used if more precision is needed
   point() { x = y = 0.0; }                      // default constructor
   point(double _x, double _y) : x(_x), y(_y) {}        // user-defined
   bool operator == (point other) const {
      return (fabs(x - other.x) < EPS && (fabs(y - other.y) < EPS)); } };

struct vec { double x, y;  // name: `vec' is different from STL vector
   vec(double _x, double _y) : x(_x), y(_y) {} };

vec toVec(point a, point b) {       // convert 2 points to vector a->b
   return vec(b.x - a.x, b.y - a.y); }

vec scale(vec v, double s) {        // nonnegative s = [<1 .. 1 .. >1]
   return vec(v.x * s, v.y * s); }               // shorter.same.longer

point translate(point p, vec v) {        // translate p according to v
   return point(p.x + v.x , p.y + v.y); }

double cross(vec a, vec b) { return a.x * b.y - a.y * b.x; }
const int N = 1004;
int cnt[2 * N][2 * N] , shift = 1000;
int add(point p , int v){
   cnt[(int)p.x + shift][(int)p.y + shift] += v;
}

double get(point p1 , point p2 , point p3){
   point fourth = translate(p1 , toVec(p1 , p2));
   fourth = translate(fourth , toVec(p1 , p3));
   int x = fourth.x , y = fourth.y;
   if(x >= -1000 && x <= 1000 && y >= -1000 && y <= 1000) {
      if (cnt[x + shift][y + shift])
         return cross(toVec(p1, p2), toVec(p1, p3));
   }
   return 0.0;
}
int main() {
#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
#endif
   ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
   int n;
   cin >> n;
   vector<point> p(n);
   for(int i = 0 ; i < n ; ++i){
      cin >> p[i].x >> p[i].y;
      add(p[i] , 1);
   }

   double ans = 0.0;
   for(int i = 0 ; i < n ; ++i){
      add(p[i] , -1);
      for(int j = i + 1 ; j < n ; ++j){
         add(p[j] , -1);
         for(int k = j + 1 ; k < n ; ++k){
            add(p[k] , -1);
            ans = max(ans , get(p[i] , p[j] , p[k]));
            ans = max(ans , get(p[j] , p[i] , p[k]));
            ans = max(ans , get(p[k] , p[i] , p[j]));
            add(p[k] , 1);
         }
         add(p[j] , 1);
      }
      add(p[i] , 1);
   }

   cout << fixed << setprecision(8) << ans << "\n";
}