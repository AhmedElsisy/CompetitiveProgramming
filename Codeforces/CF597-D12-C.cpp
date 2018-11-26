/*
    there is no duplicates so
    let c[i] be number of choices we can choose between numbers smaller than a[i] and thier indx smaller than i
    intially for each i , c[i] = 1
    we run this k + 1 times so that at k'th iteration you have stored (k - 1)'th iteration 
    so depend on values in (k - 1)'th iteration you can build k'th iteration (DP)
    we start from 2 to k + 1 , so c[i] in this iteration will be SUM of (1 to c[i] - 1 values of (k - 1) iteration)
    then update c[i] for next iteration
    so the final answer SUM for each i , c[i]
    recursive formula : c(a[j][k]) = S(for each i from 1 to a[i] - 1 , c(a[j][k - 1])) 
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
const int N = 1e5 + 4;

ll sg[4 * N] , c[N];

ll query(int p , int l , int r , int i , int j){
    if(l > j || r < i)
        return 0;
    if(l >= i && r <= j)
        return sg[p];

    int mid = (l + r) >> 1;
    return query(p * 2 , l , mid , i , j) + query(p * 2 + 1 , mid + 1 , r , i , j);
}

ll update(int p , int l , int r , int indx , ll val){
    if(indx < l || indx > r)
        return sg[p];
    if(l == r)
        return sg[p] = val;
    int mid = (l + r) >> 1;
    ll p1 = update(p * 2 , l , mid , indx , val);
    ll p2 = update(p * 2 + 1 , mid + 1 , r , indx , val);
    return sg[p] = p1 + p2;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r" , stdin);
#endif
    int n , k;
    cin >> n >> k;
    vector<int> a(n);
    int cnt = 0;
    for(int &x : a)
        cin >> x;
    
    // c(a[j][k]) = S(for each i from 1 to a[j] - 1 , c(a[i][k - 1])) 
    fill(c + 1 , c + n + 1 , 1);
    for(int i = 2 ; i <= k + 1 ; ++i){
        memset(sg , 0 , sizeof sg);
        for(int j = 0 ; j < n ; ++j){
            update(1 , 0 , n , a[j] , c[a[j]]);
            c[a[j]] = query(1 , 0 , n , 0 , a[j] - 1);
        }
    }

    ll ans = accumulate(c , c + n + 1 , 0ll);
    cout << ans << '\n';
    return 0;
}
