/*
    binary search the answer , you want to try value X can be the minimum or not
    you greedily increase any element you iterate over when it is smaller than X (and increase its window of size W)
*/
#include <bits/stdc++.h>

#define pb push_back
#define all(v) (v).begin() , (v).end()
#define popcnt(x) __builtin_popcount(x)
#define inf 0x3f3f3f3f
#define watch(x) cout << (#x) << " is " << (x) << endl

using namespace std;
typedef long long  ll;

vector<int> a;
int n , m , w;

bool valid(int mn){

    ll add = 0 , days = 0;
    vector<ll> sweep(n + 1 , 0) , tmp(all(a));
    for(int i = 0 ; i < n ; ++i){
        int r = min(n - 1 , i + w - 1);
        add += sweep[i];
        tmp[i] += add;
        int need = max(0ll , mn - tmp[i]);
        days += need;
        add += need;
        sweep[r + 1] -= need;
    }

    return days <= m;
}
int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt" , "r" , stdin);
#endif
    ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);
    cin >> n >> m >> w;

    a.resize(n);

    for(int &x : a)
        cin >> x;

    int l = 0 , r = 1e9 + 1e5 + 44 , ans = -1;

    while(l <= r){
        int mid = (l + r) >> 1;

        if(valid(mid))ans = mid , l = mid + 1;
        else r = mid - 1;

    }

    cout << ans << '\n';
}
