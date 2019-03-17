#include <bits/stdc++.h>
#define pb push_back
#define all(v) (v).begin(), (v).end()
#define popcnt(x) __builtin_popcount(x)
#define inf 0x3f3f3f3f
#define watch(x) cout << (#x) << " is " << (x) << endl
#define rand() (rand() << 15 | rand())

using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    vector<int> v;
    for (int i = 0; i < n; ++i) {
      if (s[i] == '1') {
        v.pb(i);
      }
    }

    ll total = (1ll * n * n), f = 0;
    for (int i = 0; i < (int)v.size(); ++i) {
      int indx = upper_bound(all(v), v[i] + k) - v.begin();
      int sz = indx - i;
      f += (sz + (sz - 1));
    }

    ll gcd = __gcd(f, total);
    cout << f / gcd << '/' << total / gcd << "\n";
  }
}
