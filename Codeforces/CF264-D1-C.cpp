#include <bits/stdc++.h>
#define pb push_back
#define all(v) (v).begin() , (v).end()
#define popcnt(x) __builtin_popcount(x)
#define inf 0x3f3f3f3f
#define watch(x) cout << (#x) << " is " << (x) << endl
#define rand() (rand() << 15 | rand())
using namespace std;
typedef long long  ll;
const int N = 1e5 + 4;

int v[N] , c[N] , n , q;

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt" , "r" , stdin);
#endif
    ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);
    cin >> n >> q;
    for(int i = 0 ; i < n ; ++i)
        cin >> v[i];
    for(int i = 0 ; i < n ; ++i)
        cin >> c[i];

    while(q--){
        int a , b;
        cin >> a >> b;
        vector<long long> dp(n + 1 , -1e18);
        pair<long long , int> m1 = {-1e18 , 0} , m2 = {-1e18 , 0};
        for(int i = 0 ; i < n ; ++i){
            long long add1 = 1ll * a * v[i] , add2 = 1ll * b * v[i];
            dp[c[i]] = max(dp[c[i]] , dp[c[i]] + add1);

            if(m1.second != c[i])dp[c[i]] = max(dp[c[i]] , max(0ll , m1.first) + add2);
            else dp[c[i]] = max(dp[c[i]] , max(0ll , m2.first) + add2);

            if(c[i] == m1.second)
                m1.first = max(m1.first , dp[c[i]]);

            if(dp[c[i]] > m2.first && c[i] != m1.second){
                m2 = {dp[c[i]] , c[i]};
                if(m2.first > m1.first)swap(m1 , m2);
            }
        }

        cout << max(0ll , *max_element(all(dp))) << "\n";
    }
}
