/*
    I think there are solution's ideas easier than this
    let SUM(i , j) be the sum of elements from i to j (inclusive)
    let pre[i] be SUM(1 , i) and suf[i] be SUM(i , n - 1)
    we need to count a way when
    pre[i] == suf[j] and SUM(i + 1 , j - 1) == pre[i] for some i , j and j > i + 1
    it's easy to implement using prefix sum
*/

#include <bits/stdc++.h>
#define pb push_back
#define all(v) (v).begin() , (v).end()
#define popcnt(x) __builtin_popcount(x)
#define inf 0x3f3f3f3f
#define watch(x) cout << (#x) << " is " << (x) << endl

using namespace std;
typedef long long  ll;

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r" , stdin);
#endif
    ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for(int &x : a)
        cin >> x;

    vector<int> pre(n + 1) , suf(n + 1);
    unordered_map<int , int> mp;

    suf[n - 1] = a[n - 1];
    for(int i = n - 2 ; i >= 0 ; --i){
        suf[i] = a[i] + suf[i + 1];
    }

    pre[0] = a[0];
    for(int i = 1 ; i < n ; ++i){
        pre[i] = a[i] + pre[i - 1];
    }

    for(int i = 0 ; i + 1 < n ; ++i){
        if(pre[i] == 2 * suf[i + 1])mp[suf[i + 1]]++;
    }

    ll ans = 0;
    int sum = 0;
    for(int i = 0 ; i + 1 < n ; ++i){
        if(pre[i] == 2 * suf[i + 1] && mp.count(suf[i + 1]))mp[suf[i + 1]]--;
        sum += a[i];
        ans += (mp.count(sum) ? mp[sum] : 0);
    }

    cout << ans << '\n';

}

