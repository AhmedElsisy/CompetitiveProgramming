#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int MOD;
int coff[15];
struct mat{
   static const int M = 15;
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
   int d;
   while(cin >> d >> n >> MOD && d && n && MOD) {
      for(int i = 0 ; i < d ; ++i)
         cin >> coff[i];
      mat base;
      for (int i = 0; i < d; ++i) {
         int x;
         cin >> x;
         base[0][d - i - 1] = x;
      }
      if (n <= d) {
         cout << base[0][d - n] << "\n";
         continue;
      }
      mat trans(0);
      for (int i = 0; i < d; ++i)
         trans[i][0] = coff[i];
      for (int i = 1; i < d; ++i)
         trans[i - 1][i] = 1;
      trans = trans ^ (n - d);
      base = base * trans;
      cout << base[0][0] << "\n";
   }
}