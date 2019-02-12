/*
    binary search the answer we want number X s.t. number of elements in grid smaller than or equal X >= k
    output smallest X satisfy the above conditions
    to calculate the number of elements smaller than or equal X in grid you have to iterate over rows or columns
*/
#include <bits/stdc++.h>

#define pb push_back
#define all(v) (v).begin() , (v).end()
#define popcnt(x) __builtin_popcount(x)
#define inf 0x3f3f3f3f
#define watch(x) cout << (#x) << " is " << (x) << endl

using namespace std;
typedef long long  ll;
const int N = 5e5 + 4;
int n , m;
ll k;

bool valid(ll mid){
    ll smaller = 0;
    for(int i = 1 ; i <= m ; ++i)
        smaller += min(1ll * i * n , mid) / i;
    return smaller >= k;
}
int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt" , "r" , stdin);
#endif
    ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);
    cin >> n >> m >> k;

    ll l = 1 , r = 1ll * N * N , ans = -1;
    while(l <= r){
        ll mid = (l + r) / 2;

        if(valid(mid))ans = mid , r = mid - 1;
        else l = mid + 1;
    }

    cout << ans << '\n';
}
