/**
 * DP + printpath
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
#define PI acos(-1.0)
const int N = 104;
int memo[N][N];
string s;
char close(char c){
   if(c == '(')
      return ')';
   if(c == '[')
      return ']';
}
char open(char c){
   if(c == ')')
      return '(';
   if(c == ']')
      return '[';
}
int solve(int l , int r){
   if(l > r)
      return 0;
   int &ret = memo[l][r];
   if(~ret)
      return ret;
   ret = inf;
   if(s[l] == ')' || s[l] == ']'){
      ret = min(ret , 1 + solve(l + 1 , r));
   }
   if(s[r] == '(' || s[r] == '['){
      ret = min(ret , 1 + solve(l , r - 1));
   }
   if((s[l] == '(' || s[l] == '[') && s[r] == close(s[l])){
      ret = min(ret , solve(l + 1 , r - 1));
   }
   for(int i = l ; i < r ; ++i)
      ret = min(ret , solve(l , i) + solve(i + 1 , r));
   return ret;
}

void p(int l , int r){
   if(l > r)
      return;
   if(s[l] == ')' || s[l] == ']'){
      if(solve(l , r) == 1 + solve(l + 1 , r)){
         cout << open(s[l]);
         cout << s[l];
         p(l + 1 , r);
         return;
      }
   }
   if(s[r] == '(' || s[r] == '['){
      if(solve(l , r) == 1 + solve(l , r - 1)){
         p(l , r - 1);
         cout << s[r];
         cout << close(s[r]);
         return;
      }
   }
   if((s[l] == '(' || s[l] == '[') && s[r] == close(s[l])){
      if(solve(l , r) == solve(l + 1 , r - 1)){
         cout << s[l];
         p(l + 1 , r - 1);
         cout << s[r];
         return;
      }
   }
   for(int i = l ; i < r ; ++i){
      if(solve(l , r) == solve(l , i) + solve(i + 1 , r)){
         p(l , i);
         p(i + 1 , r);
         return;
      }
   }
}
int main() {
#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
#endif
   ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
   int t;
   cin >> t;
   getline(cin , s);
   while(t--){
      getline(cin , s);
      getline(cin , s);
      memset(memo , -1 , sizeof(memo));
      p(0 , (int)s.size() - 1);
      cout << "\n";
      if(t)
         cout << "\n";
   }
}
