#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;
int mul(int a , int b , int m = MOD){
   return (1LL * (a % m) * (b % m)) % m;
}

int add(int a , int b , int m = MOD){ // moded
   a += b;
   while(a >= MOD)a -= MOD;
   while(a < 0) a += MOD;
   return a;
}

int powMOD(int x , int n , int m = MOD){
   if(!n)return 1;
   int ret = 1;
   if(n & 1)ret = mul(x , powMOD(x , n - 1 , m) , m);
   else{
      int y = powMOD(x , n / 2 , m);
      ret = mul(y , y , m);
   }
   return ret;
}

int main() {
#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
#endif
   ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
   int t , cs = 1;
   cin >> t;
   while(t--){
      int n;
      cin >> n;
      // how many to choose teams with captain
      // for each team of size k you choose you can pick k captians
      // so SUMATION (nCk * k) is the answer
      // but we can look in different way for each member how many ways to pick a team and he's the captian
      // 2^(n - 1) and you can choose n captians so the answer = n * 2^(n-1)
      // so SUMATION (nCk * k) = n * 2^(n - 1)
      printf("Case #%d: %d\n" , cs++ , mul(n , powMOD(2 , n - 1)));
   }
}