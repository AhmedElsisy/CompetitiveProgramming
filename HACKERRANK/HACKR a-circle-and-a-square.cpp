/**
 *      Link: https://www.hackerrank.com/challenges/a-circle-and-a-square/problem
 *      - circle is trivial but the problem with the square
 *       side length of the square can be found easily by pythagorean theorem between x1,y1 & x2,y2
 *       the sub problem is to find the vertices of the square and using function inSide() we can check
 *       for every point (x,y) whether it lies on the square or not.
 *
 *      - point is inside a square if the sum areas of triangulation of square points with this point is equal to area of the square
 *      - let D is the distance between p1 , p2 I think we can get an extra point of the square if we get the middle point (distance D / 2)
 *      between the vector p1 -> p2 and move perpendicularly with the same distance D / 2
 *
 *      - case of fail assuming that square vertices will be at integer cordinate
 *          30 20
            14 6 4
            24 4 11 6
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

double dist(point p1, point p2) {                // Euclidean distance
   return hypot(p1.x - p2.x, p1.y - p2.y); }           // return double

double cross(vec a, vec b) { return a.x * b.y - a.y * b.x; }

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
   vector<point> squarePoints;
   // here we're finding the other points of the square using vector scaling and transforming
   vec p12 = toVec(p1 , p2);
   p12 = scale(p12 , 0.5);
   point p = translate(p1 , p12);
   swap(p12.x , p12.y);
   p12.x *= -1;
   point p3 = translate(p , p12);
   squarePoints.pb(p1);
   squarePoints.pb(p3);
   squarePoints.pb(p2);
   p12 = scale(p12 , -2);
   p3 = translate(p3 , p12);
   squarePoints.pb(p3);
   // we got all square point
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