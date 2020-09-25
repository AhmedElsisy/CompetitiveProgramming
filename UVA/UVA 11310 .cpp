#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 41;
long long dp[N];
int main() {
#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
#endif
   ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

   dp[0] = 1;
   for(int i = 1 ; i < N ; ++i){
      dp[i] = dp[i - 1];
      if(i >= 2)dp[i] += 4 * dp[i - 2];
      if(i >= 3)dp[i] += 2 * dp[i - 3];
   }

   int t;
   cin >> t;
   while(t--){
      int n;
      cin >> n;
      cout << dp[n] << '\n';
   }
}