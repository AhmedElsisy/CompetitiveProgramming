#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const long double PI = acos(-1);

long double getTheta(long double b , long double c , long double a){
   long double cosTheta = (b * b + c * c - a * a) / (2 * b * c);
   return acos(cosTheta);
}

long double arcArea(vector<long double> R , int j){
   vector<long double> sides;
   long double a = 0;
   for(int i = 0 ; i < 3 ; ++i){
      if(i == j)continue;
      a += R[i];
      sides.push_back(R[i] + R[j]);
   }

   long double theta = getTheta(sides[0] , sides[1] , a);
   return (PI * R[j] * R[j]) * (theta / (2 * PI));
}

long double triangleArea3sides(long double a, long double b, long double c) {
   long double s = ((a + b + c) / 2);
   return sqrt(s * (s - a) * (s - b) * (s - c));
}

void solve(){
   vector<long double> R(3);
   for(auto &x : R)
      cin >> x;

   vector<long double> sides;
   for(int i = 0 ; i < 3 ; ++i){
      for(int j = i + 1 ;j < 3 ; ++j){
         sides.push_back(R[i] + R[j]);
      }
   }

   long double res = triangleArea3sides(sides[0] , sides[1] , sides[2]);
   for(int i = 0 ; i < 3 ; ++i)
      res -= arcArea(R , i);
   cout << fixed << setprecision(6) << res << "\n";
}
int main() {
#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
#endif
   ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
   int t;
   cin >> t;
   while(t--){
      solve();
   }
}