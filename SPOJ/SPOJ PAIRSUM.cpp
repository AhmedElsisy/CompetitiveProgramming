/*
    all indexes in 1-based format
    solving each query in O(n) , query(u , v) = a[i] * sum(u , i) {for each i from u to v}
    to convery it into O(1) lets preprocess prefixsum called s[]
    let c[i] is the answer to query(1 , i) by solving each index from 1 to i and run prefixsum on this array
    1 2 3 4 5 6 7 u .... v
    the answer to query(u , v) will be c[v] - (s[v] - s[u - 1]) * s[u - 1]) - c[u - 1]
    total complexity : O(n + m)
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
vector<ll> s , c;

ll solve(int u , int v){
    ll ret = c[v];
    ret -= 1ll * s[u - 1] * (s[v] - s[u - 1]);
    ret -= c[u - 1];
    return ret;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r" , stdin);
#endif
    ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);
    // 21:12

    int n , m;
    scanf("%d" , &n);
    vector<int> a(n + 1);
    for(int i = 1 ; i <= n ; ++i){
        scanf("%d" , &a[i]);
    }
    s.assign(n + 1 , 0);
    c.assign(n + 1 , 0);
    partial_sum(all(a) , s.begin());
    for(int i = 1 ; i <= n ; ++i)
        c[i] = 1ll * s[i] * a[i];
    partial_sum(all(c) , c.begin());

    scanf("%d" , &m);
    while(m--){
        int u , v;
        scanf("%d %d" , &u , &v);
        ++u , ++v;
        printf("%lld\n" , solve(u , v));
    }
}
