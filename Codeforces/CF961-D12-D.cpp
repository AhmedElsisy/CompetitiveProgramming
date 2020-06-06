/**
 *      link:   https://codeforces.com/problemset/problem/961/D
 *      another editorial : https://www.quora.com/How-do-I-solve-Pair-of-Lines-961D-on-Codeforces/answer/Saikat-Ghosh-183
 *
 *      - if we reduced this problem into just one line so I think it's much easier so we are sure that the line will be
 *      the line between any pair of points the rest of points must lie on this line.
 *
 *      - If the number of points is less than 3, then the answer is obviously YES.
 *      Else let's fix first 3 points. Check if there is a solution if 1-st and 2-nd points lie on the same line.
 *      Just erase all points which lie on this line and check the remaining points if they belong to one line.
 *      If we didn't find the answer, let's check points 1 and 3 in the same way.
 *      If its failed again then line which contains point 1 can't contain points 2 and 3, so points 2 and 3 must lie on one line. I
 *      f we didn't succeed again, then there is no way to do it, so the answer is NO.
 *      Checking that points a, b and c belong to the same line can be done by checking slopes
 *      or calculating 2d version of cross product (b - a) × (c - a). It equals to 0 if vectors (b - a) and (c - a) are collinear.
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
const int N = 1e5 + 4;
int n;
pair<int , int> a[N];
bool used[N];

pair<int , int> get(pair<int , int> f , pair<int , int> s){
   int dx = abs(f.first - s.first) , dy = abs(f.second - s.second);
   if(!dx)
      return {1 , 0};
   if(!dy)
      return {0 , 1};
   bool flag = false;
   if(f.first < s.first)flag ^= 1;
   if(f.second < s.second)flag ^= 1;
   int gcd = __gcd(dx , dy);
   return {(flag ? -1 : 1) * dx / gcd , dy / gcd};
}

bool go2(){
   vector<pair<int , int>> rest;
   for(int i = 0 ; i < n ; ++i){
      if(!used[i]){
         rest.pb(a[i]);
      }
   }
   if(rest.size() <= 2)
      return true;
   pair<int , int> slope = get(rest[0] , rest[1]);
   for(int i = 2 ; i < rest.size() ; ++i){
      pair<int , int> curSlope = get(rest[0] , rest[i]);
      if(curSlope != slope)
         return false;
   }
   return true;
}

bool go(int f , int s){
   pair<int , int> slope = get(a[f] , a[s]);
   memset(used , 0 , sizeof(used));
   used[f] = used[s] = true;
   for(int i = 0 ; i < n ; ++i){
      if(i == f)continue;
      pair<int , int> curSlope = get(a[f] , a[i]);
      if(curSlope == slope){
         used[i] = true;
      }
   }
   return go2();
}

int main() {
#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
#endif
   ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
   cin >> n;
   for(int i = 0 ; i < n ; ++i)
      cin >> a[i].first >> a[i].second;
   if(n <= 3 || go(0 , 1) || go(0 , 2) || go(1 , 2)){
      cout << "YES\n";
   }
   else cout << "NO\n";

}