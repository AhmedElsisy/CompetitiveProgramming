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
/**
 * 10 <= h , w <= 100
 * -100 <= x , y <= 200
 * 0 <= r <= 100
 *
 * circle is trivial but the problem with the square
 * side length of the square can be found easily by pythagorean theorem between x1,y1 & x2,y2
 * point is inside a square if the sum areas of triangulation of square points with this point is equal to area of the square
 */
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

double dist(point p1, point p2) {                // Euclidean distance
   return hypot(p1.x - p2.x, p1.y - p2.y); }           // return double

double dot(vec a, vec b) { return (a.x * b.x + a.y * b.y); }

double norm_sq(vec v) { return v.x * v.x + v.y * v.y; }

double angle(point a, point o, point b) {  // returns angle aob in rad
   vec oa = toVec(o, a), ob = toVec(o, b);
   return acos(dot(oa, ob) / sqrt(norm_sq(oa) * norm_sq(ob))); }

double cross(vec a, vec b) { return a.x * b.y - a.y * b.x; }

// note: to accept collinear points, we have to change the `> 0'
// returns true if point r is on the left side of line pq
bool ccw(point p, point q, point r) {
   return cross(toVec(p, q), toVec(p, r)) > 0; }

// returns true if point r is on the same line as the line pq
bool collinear(point p, point q, point r) {
   return fabs(cross(toVec(p, q), toVec(p, r))) < EPS; }

// returns true if we always make the same turn while examining
// all the edges of the polygon one by one

bool inPolygon(point pt, const vector<point> &P) {
   if ((int) P.size() == 0) return false;
   double sum = 0;    // assume the first vertex is equal to the last vertex
   for (int i = 0; i < (int) P.size() - 1; i++) {
      if (ccw(pt, P[i], P[i + 1]))
         sum += angle(P[i], pt, P[i + 1]);                   // left turn/ccw
      else sum -= angle(P[i], pt, P[i + 1]);
   }                 // right turn/cw
   return fabs(fabs(sum) - 2 * PI) < EPS;
}
point pivot;
bool angleCmp(point a, point b) {                 // angle-sorting function
   if (collinear(pivot, a, b))                               // special case
      return dist(pivot, a) < dist(pivot, b);    // check which one is closer
   double d1x = a.x - pivot.x, d1y = a.y - pivot.y;
   double d2x = b.x - pivot.x, d2y = b.y - pivot.y;
   return (atan2(d1y, d1x) - atan2(d2y, d2x)) < 0; }   // compare two angles

vector<point> CH(vector<point> P) {   // the content of P may be reshuffled
   int i, j, n = (int) P.size();
   if (n <= 3) {
      if (!(P[0] == P[n - 1])) P.push_back(P[0]); // safeguard from corner case
      return P;                           // special case, the CH is P itself
   }

   // first, find P0 = point with lowest Y and if tie: rightmost X
   int P0 = 0;
   for (i = 1; i < n; i++)
      if (P[i].y < P[P0].y || (P[i].y == P[P0].y && P[i].x > P[P0].x))
         P0 = i;

   point temp = P[0];
   P[0] = P[P0];
   P[P0] = temp;    // swap P[P0] with P[0]

   // second, sort points by angle w.r.t. pivot P0
   pivot = P[0];                    // use this global variable as reference
   sort(++P.begin(), P.end(), angleCmp);              // we do not sort P[0]

   // third, the ccw tests
   vector<point> S;
   S.push_back(P[n - 1]);
   S.push_back(P[0]);
   S.push_back(P[1]);   // initial S
   i = 2;                                         // then, we check the rest
   while (i < n) {           // note: N must be >= 3 for this method to work
      j = (int) S.size() - 1;
      if (ccw(S[j - 1], S[j], P[i])) S.push_back(P[i++]);  // left turn, accept
      else S.pop_back();
   }   // or pop the top of S until we have a left turn
   return S;
}// return the result
point p1 , p2 , circleCenter;
int h , w , r;
const int N = 304;
bool a[N][N];
void fillCircle(){
   for(int i = 0 ; i < h ; ++i){
      for(int j = 0 ; j < w ; ++j){
         point cur(i , j);
         if(dist(circleCenter , cur) < r + EPS){
            a[i][j] = true;
         }
      }
   }
}
double area(point a , point b , point c){
   return fabs(cross(toVec(a , b) , toVec(a , c))) / 2.0;
}
bool inside(vector<point> &squarePoints , point p , double A){
   double totalArea = 0.0;
   for(int i = 0 ; i < 4 ; ++i){
      point p1 = squarePoints[i] , p2 = squarePoints[(i + 1) % 4];
      totalArea += area(p , p1 , p2);
   }
   return fabs(totalArea - A) < EPS;
}
void fillSquare(){
   double d = dist(p1 , p2);
   d *= d;
   double sideLen = sqrt(d / 2);
   vector<point> squarePoints , tmp;
   for(int i = -1000 ; i < 1001 ; ++i){
      for(int j = -1000 ; j < 1001 ; ++j){
         point cur(i , j);
         double d1 = dist(cur , p1) , d2 = dist(cur , p2);
         if(fabs(d1 - d2) < EPS && fabs(d1 - sideLen) < EPS){
            tmp.pb(cur);
         }
      }
   }
   /*
     case of fail RTE (i think because the sqrt function so we have to calc distance squared)
     after AC save(library) boolean inrectangle function (point , vector<point>)
      30 20
      14 6 4
      24 4 11 6
    */
//   watch(sideLen);
//   watch(tmp.size());
//   return;
   squarePoints.pb(p1);
   squarePoints.pb(tmp[0]);
   squarePoints.pb(p2);
   squarePoints.pb(tmp[1]);
   for(int i = 0 ; i < h ; ++i){
      for(int j = 0 ; j < w ; ++j){
         point cur(i , j);
         if(inside(squarePoints , cur , sideLen * sideLen)){
            a[i][j] = true;
         }
      }
   }
}
int main() {
#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
#endif
   ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
   cin >> w >> h;
   cin >> circleCenter.y >> circleCenter.x >> r;
   cin >> p1.y >> p1.x >> p2.y >> p2.x;
   fillCircle();
   fillSquare();
   for(int i = 0 ; i < h ; ++i){
      for(int j = 0 ; j < w ; ++j){
         cout << (a[i][j] ? '#' : '.');
      }
      cout << "\n";
   }
}