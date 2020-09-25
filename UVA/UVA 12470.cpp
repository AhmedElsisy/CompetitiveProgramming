#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9+9;

struct mat{
   static const int M = 3;
   int a[M][M];
   mat(bool v = 0){
      memset(a, 0, sizeof a);
      for(int i = 0; i < M; i++)  a[i][i] = v;
   }
   int* operator[](int idx){
      return a[idx];
   }
   mat operator *(mat &b){
      mat ans;
      for(int i = 0; i < M; i++)
         for(int k = 0; k < M; k++)
            for(int j = 0; j < M; j++)
               ans[i][j] = (ans[i][j] + a[i][k] * 1ll * b[k][j]) % MOD;
      return ans;
   }

   mat operator +(mat &b){
      mat ans;
      for(int i = 0; i < M; i++)
         for(int j = 0; j < M; j++)
            ans[i][j] = (a[i][j] + b[i][j]) % MOD;

      return ans;
   }
};

mat operator ^(mat a, long long b){
   mat ans(1);
   for( ; b; b >>= 1, a = a * a)
      if(b & 1)
         ans = ans * a;
   return ans;
}


int main() {
#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
#endif
   ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
   long long n;
   while(cin >> n && n){
      mat base;
      base[0][0] = 2 , base[0][1] = 1 , base[0][2] = 0;
      if(n <= 3){
         cout << base[0][3 - n] << "\n";
         continue;
      }
      mat trans(0);
      for(int i = 0 ; i < 3 ; ++i)
         for(int j = 0 ; j < 3 ; ++j)
            trans[i][j] = 1;
      trans[0][2] = 0 , trans[1][1] = 0 , trans[2][1] = 0 , trans[2][2] = 0;
      trans = trans ^ (n - 3);
      base = base * trans;
      cout << base[0][0] << "\n";
   }
}