/*
 * key idea of this problem that inscribed right triangle in a circle its hypotenuse is a diameter of the circle
 * so check every two point infront of each other are reds if yes add (redPoints - 2) to the answer
 * https://en.wikipedia.org/wiki/Thales%27s_theorem
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

void build(int m , int n , vector<bool> &red , int a , int b , int c){
   set<int> s;
   for(int i = 0 ; i < n ; ++i)s.insert(i);
   for(int i = 0 ; i < m ; ++i){
      long long p = (1ll * a * i * i + 1ll * b * i + c) % n;
      auto it = s.lower_bound(p);
      if(it == s.end())
         it = s.begin();
      red[*it] = true;
      s.erase(it);
   }
}
class RightTriangle{
public:
   long long triangleCount(int places, int points, int a, int b, int c){
      vector<bool> red(places , false);
      build(points , places , red , a , b , c);
      if(places & 1)
         return 0;
      int h = places / 2;
      long long rt = 0;
      for(int i = 0 ; i < h ; ++i){
         if(red[i] && red[i + h]){
            rt += (points - 2);
         }
      }
      return rt;
   }
};
