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

struct Node {
   Node* childs[26];
   int cnt;
   Node() {
      cnt = 0;
      for (auto& child : childs) child = NULL;
   }

   ~Node() {
      for (auto& child : childs) delete child;
   }
};

struct Trie {
   Node* root;

   Trie() { root = new Node(); }

   ~Trie() { delete root; }

   void insert(string s) {
      Node* node = root;
      for (const char& c : s) {
         if (node->childs[c - 'a'] == NULL) node->childs[c - 'a'] = new Node();
         node = node->childs[c - 'a'];
      }
      node->cnt++;
   }

   int query(string s) {
      Node* node = root;
      for(const char&c : s){
         if(node->childs[c - 'a'] == NULL)return 0;
         node = node->childs[c - 'a'];
      }
      return node->cnt;
   }
};

int dfs(Node *root){
   for(char c = 'a' ; c <= 'z' ; ++c){
      if(root->childs[c - 'a'] != NULL){
         root->cnt += dfs(root->childs[c - 'a']);
      }
   }
   return root->cnt;
}

string t;
int solve(Node *root , int i , int d){
   if(root->cnt + d < 1)
      return 0;
   int rt = 1;
   if(i != (int)t.size()) {
      auto c = root->childs[t[i] - 'a'];
      if (c != NULL)
         rt += solve(c, i + 1, min(d + root->cnt - c->cnt - 1, 0));
   }
   return rt;
}

int main() {
#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
#endif
   ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
   int n , m;
   while(cin >> n >> m){
      Trie tr;
      vector<string> v(n);
      for(int i = 0 ; i < n ; ++i)
         cin >> v[i];
      for(int i = 0 ; i < m ; ++i){
         string s;
         cin >> s;
         tr.insert(s);
      }
      dfs(tr.root);
      long long rs = 0;
      for(auto &s : v){
         t = s;
         auto c = tr.root->childs[t[0] - 'a'];
//         cout << c->cnt << "\n";
         if(c != NULL)rs += solve(c , 1 , 0);
      }
      cout << rs << "\n";
   }
}