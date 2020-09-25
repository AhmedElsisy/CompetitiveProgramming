#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
#endif
   ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
   int cs = 1, n;
   while(cin >> n && n){
      long long rs = 0;
      for(int i = 1 ; i <= n / 3 ; ++i){
         int rm = n - i;
         int md = (rm + 1) / 2;
         rs += max(0 , md - (i + 1));
      }
      cout << "Case " << cs++ << ": " << rs << "\n";
   }
}