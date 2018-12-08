/*
    editorial solution
    make a bipartite graph of floor(n / 2) * ceil(n / 2) edges
    if we add any extra edge then it won't satisfy the constraints (there is no cycle of size 3)
*/

#include <bits/stdc++.h>
#define pb push_back
#define all(v) (v).begin() , (v).end()
#define popcnt(x) __builtin_popcount(x)
#define inf 0x3f3f3f3f
#define watch(x) cout << (#x) << " is " << (x) << endl
#define F first
#define S second

using namespace std;
typedef long long  ll;

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r" , stdin);
#endif
    int n;
    cin >> n;
    cout << (int)n / 2 * (int)ceil(1.0 * n / 2) << '\n';
    for(int i = 1 ; i <= n / 2 ; ++i)
        for(int j = n / 2 + 1 ; j <= n ; ++j)
            cout << i << ' ' << j << '\n';
}
