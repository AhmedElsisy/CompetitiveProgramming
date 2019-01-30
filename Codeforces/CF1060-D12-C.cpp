/*
    an element c[i][j] is formed by multiplication of a[i] and b[j]
    so if we have {x1 , y1} and {x2 , y2} the result sub-grid will be of size 2 * 2
    and its elements sum (x1 * x2) + (x1 * y2) + (y1 * x2) + (y1 * y2) and it can be in different form (x1 + y1) * (x2 + y2)
    in another words : the sum of the sub-grid is sum of the sub array from the first array multiply by sum of the sub array form the second one
    for each sz in both array we pre-processed the minimum sum of sub array of size sz
    then brute force over the sizes of the first array and the sizes of the second one
*/

#include <bits/stdc++.h>

#define pb push_back
#define all(v) (v).begin() , (v).end()
#define popcnt(x) __builtin_popcount(x)
#define inf 0x3f3f3f3f
#define watch(x) cout << (#x) << " is " << (x) << endl

using namespace std;
typedef long long  ll;

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt" , "r" , stdin);
#endif
    ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);
    int n , m;
    cin >> n >> m;
    vector<int> a(n);
    for(int &x : a)
        cin >> x;

    vector<int> b(m);
    for(int &x : b)
        cin >> x;


    int max_sum;
    cin >> max_sum;


    vector<int> mnszA(n + 1 , inf) , mnszB(m + 1 , inf);
    for(int i = 0 ; i < n ; ++i){
        int sum = 0;
        for(int j = i ; j < n ; ++j){
            int sz = j - i + 1;
            sum += a[j];
            mnszA[sz] = min(sum , mnszA[sz]);
        }
    }

    for(int i = 0 ; i < m ; ++i){
        int sum = 0;
        for(int j = i ; j < m ; ++j){
            int sz = j - i + 1;
            sum += b[j];
            mnszB[sz] = min(sum , mnszB[sz]);
        }
    }

    int ans = 0;
    for(int i = 1 ; i <= n ; ++i){
        for(int j = 1 ; j <= m ; ++j){
            ll total = 1ll * mnszA[i] * mnszB[j];
            if(total <= max_sum)ans = max(ans , i * j);
        }
    }

    cout << ans << '\n';
}
