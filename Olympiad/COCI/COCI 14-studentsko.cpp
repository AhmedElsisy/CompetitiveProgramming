/*
    choose the longest valid sequence and insert the rest of the elements in it
    it can be solved using dp (longest increasing/decreasing sub-sequence)
    total complexity : O(N^2)
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
    ios::sync_with_stdio() , cin.tie(0) , cout.tie(0);
    int n , k;
    cin >> n >> k;

    vector<int> a(n);
    for(int &x : a)
        cin >> x;

    vector<int> s(all(a));

    sort(all(s));

    for(int &x : a)
        x = (lower_bound(all(s) , x) - s.begin()) / k + 1;

    vector<int> dp(n , 1);
    for(int i = 0 ; i < n ; ++i){
        for(int j = i + 1 ; j < n ; ++j){
            if(a[j] >= a[i])dp[j] = max(dp[j] , dp[i] + 1);
        }
    }

    cout << n - *max_element(all(dp)) << '\n';
}
