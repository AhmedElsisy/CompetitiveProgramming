/*
    using dynamic programming we can solve this problem with this recurrence
    dp(i , k) = min( for each m <= k , dp(i + 1 , k - m)
    total complexity : O(m * k * k)
*/

#include <bits/stdc++.h>
#define pb push_back
#define all(v) (v).begin() , (v).end()
#define popcnt(x) __builtin_popcount(x)
#define inf 0x3f3f3f3f
#define watch(x) cout << (#x) << " is " << (x) << endl

using namespace std;
typedef long long  ll;
const int N = 105 , K = 504;

ll dp[N][K];
int a[N] , n , m , k;

ll sum(int n){
    return 1ll * n * (n + 1) / 2;
}

ll getValue(int n , int k){
    ++k;
    ll ret = 0;
    int v = n / k , mod = n % k;
    if(mod){
        ret = 1ll * (k - mod) * sum(v);
        ret += 1ll * (mod) * sum(v + 1);
    }
    else ret = 1ll * k * sum(v);
    return ret;
}

int main() {
    ios::sync_with_stdio() , cin.tie(0) , cout.tie(0);

    cin >> n >> m >> k;

    while(n--){
        int x;
        cin >> x;
        a[x]++;
    }

    for(int indx = m ; indx >= 1 ; --indx){
        for(int remk = k ; remk >= 0 ; --remk){
            dp[indx][remk] = LLONG_MAX / 2;
            for(int i = 0 ; i <= remk ; ++i)
                dp[indx][remk] = min(dp[indx][remk] , getValue(a[indx] , i) + dp[indx + 1][remk - i]);
        }
    }

    cout << dp[1][k] << '\n';
}
