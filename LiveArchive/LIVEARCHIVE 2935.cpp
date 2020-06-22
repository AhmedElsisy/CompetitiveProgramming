/*
 * check canonical form : https://www.youtube.com/watch?v=RASvnfG2SSE&feature=youtu.be&t=734
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
const int N = 4005;
vector<int> adj[N];
int p[N];

string dfs_match(int u){
   string rt = "(";
   vector<string> vc;
   for(int c : adj[u])
      vc.pb(dfs_match(c));
   sort(all(vc));
   for(auto e : vc)
      rt += e;
   rt += ")";
   return rt;
}
string canonial_form(int root = 1){
   return dfs_match(root);
}

string get_tree(string t1){
   int node = 1 , nxt = 2;
   for(char c : t1){
      if(c == '0'){
         adj[node].pb(nxt);
         p[nxt] = node;
         node = nxt++;
      }
      else{
         node = p[node];
      }
   }
   t1 = canonial_form();
   for(int i = 1 ; i <= nxt ; ++i)
      adj[i].clear() , p[i] = 0;
   return t1;
}

int main() {
#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
#endif
   ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
   int t;
   cin >> t;
   while(t--){
      string t1 , t2;
      cin >> t1 >> t2;
      t1 = get_tree(t1);
      t2 = get_tree(t2);
      cout << (t1 == t2 ? "same" : "different") << "\n";
   }
}
