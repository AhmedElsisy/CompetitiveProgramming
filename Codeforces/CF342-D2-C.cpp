/**
 *      link:https://codeforces.com/contest/342/problem/C
 *      - first of all as the depth of the cardboard is r then we can assume 2d plane instead of 3d
 *      because the depth won't carry more than one shpere so reduce the problem into 2D and shpere into circle
 *
 *      - two cases:
 *      1) if we put one circle in the top of the cardbaord (we need to handle the distance we can lift the remaining circle above alittle bit using pythagorean theorem)
 *      2) if we didn't we can put two circles in the end of the rectangle and the remaining height will be h - (r / 2)
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

double get(double a , double b){
   return sqrt(a * a - b * b);
}

int main() {
#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
#endif
   ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
   double r , h;
   cin >> r >> h;
   double extra = (r - get(r , r / 2));
   h += extra;
   int ans = 2 * (int)(h / r) + 1;
   h -= extra;
   h += r / 2.0;
   ans = max(ans , 2 * (int)(h / r));
   cout << ans << "\n";
}