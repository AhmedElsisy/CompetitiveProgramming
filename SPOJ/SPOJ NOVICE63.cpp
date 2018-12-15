/*
    let dp[sz][0][0] be number of elements we can form of size sz
    using dp knapsack we have two choices in each state 1) put zero , 2) put one
*/
#include <bits/stdc++.h>
#define pb push_back
#define all(v) (v).begin() , (v).end()
#define popcnt(x) __builtin_popcount(x)
#define inf 0x3f3f3f3f
#define watch(x) cout << (#x) << " is " << (x) << endl

using namespace std;
typedef long long  ll;

ll memo[64][64][64];

ll solve(int rem , int zero , int one){
    if(!rem)
        return zero == one && zero > 0;

    ll &ret = memo[rem][zero][one];
    if(~ret)
        return ret;
    ret = 0;

    // put zero
    ret += solve(rem - 1 , zero + (one > 0) , one);
    // put one
    ret += solve(rem - 1 , zero , one + 1);

    return ret;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r" , stdin);
#endif
    ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);
    memset(memo , -1 , sizeof memo);

    int t;
    cin >> t;
    while(t--){

        ll n;
        cin >> n;
        // range [ 1 : n ] (inclusive)
        if(n == 2){
            cout << 1 << '\n';
            continue;
        }
        int sz = log2(n);
        cout << solve(sz , 0 , 0) << '\n';
    }
}

