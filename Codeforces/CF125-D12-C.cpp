/*
it's obvious that
we need to make a complete graph with n edges(so that every two vertices(days) have a common edge(hobbit)).
so we search for m (number of vertices)
s.t. (m * (m - 1) / 2) <= n , we use binary search to find that number
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
const int N = 1e4 + 3;

vector<int> res[N];

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r" , stdin);
#endif
    int n;
    cin >> n;
    int ans = 0;

    int l = 0 , r = N;
    while(l <= r){
        int mid = (l + r) / 2;
        if((mid * (mid - 1)) / 2 <= n)ans = mid , l = mid + 1;
        else r = mid - 1;
    }

    int cur = 1;
    cout << ans << '\n';
    for(int i = 0 ; i < ans ; ++i){
        for(int j = i + 1 ; j < ans ; ++j){
            res[i].pb(cur);
            res[j].pb(cur);
            ++cur;
        }
    }

    for(int i = 0 ; i < ans ; ++i){
        for(int x : res[i])
            cout << x << ' ';
        cout << '\n';
    }
}
