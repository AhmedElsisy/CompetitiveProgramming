/*
 * let entering and leaving of person be an event
 * for each leaving event we can meet some persons now if we enter at this moment
 * if number of person we can meet >= p then the answer is zero
 * otherwise let K be number of extra persons we need to meet if we enter at this moment
 * so the optimal K persons we can meet are the next K person will enter (if exist)
 * so we keep track the upcoming entering persons sorted and ask for kth smallest entering event
 * we can make this operation at every event and minimizing the answer
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
int cs = 1;
void solve() {
   int n , p;
   cin >> n >> p;
   map<int , vector<int>> st;
   map<int , int> en , events;
   ordered_set<pair<int , int>> os;
   for(int i = 0 ; i < n ; ++i){
      int l , r;
      cin >> l >> r;
      st[l].pb(i);
      en[r]++;
      events[l];
      events[r];
      os.insert(make_pair(l , i));
   }

   int meeting = 0 , rs = INT_MAX;
   for(auto &e : events){
      int cr = e.first;
      for(int i : st[cr])
         os.erase(make_pair(cr, i));
      meeting += (int)st[cr].size();
      int k = max(0 , p - meeting);
      if(k){
         // fint kth minimum start event
         if((int)os.size() >= k){
            int to = (*os.find_by_order(k - 1)).first;
            rs = min(rs , to - cr);
         }
      }
      else rs = 0;
      meeting -= en[cr];
   }
   cout << "Case " << cs++ << ": " << rs << "\n";
}

int main() {
#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
#endif
   ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
   int t = 1;
   cin >> t;
   while(t--){
      solve();
   }
}