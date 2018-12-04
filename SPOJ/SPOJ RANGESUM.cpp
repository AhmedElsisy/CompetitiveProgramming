/*
    shift the indexes of the original array 1e5 (maximum number of insertion operations)
    and insert (query number 2)first number in 1e5 - 1 , 1e5 - 2 , ... , 0
    and track the beginning of the array after insertions
    let beg be the index of the beginning of the array
    to answer query you should convert l , r to your shifting indexes
    so that newL = beg + (l - 1) , newR = beg + (r - 1)
    total complexity : O(m log N)
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

const int N = 2e5 + 4;
ll sg[4 * N];

ll update(int p , int l , int r , int indx , int val){
    if(indx < l || indx > r)
        return sg[p];
    if(l == r)
        return sg[p] = val;

    int mid = (l + r) >> 1;
    ll p1 = update(p * 2 , l , mid , indx , val);
    ll p2 = update(p * 2 + 1 , mid + 1 , r , indx , val);
    return sg[p] = p1 + p2;
}

ll query(int p , int l , int r , int i , int j){
    if(l > j || r < i)
        return 0;
    if(l >= i && r <= j)
        return sg[p];
    int mid = (l + r) >> 1;
    ll p1 = query(p * 2 , l , mid , i , j);
    ll p2 = query(p * 2 + 1 , mid + 1 , r , i , j);
    return p1 + p2;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r" , stdin);
#endif
    ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);
    int n;
    cin >> n;
    int beg = 1e5 + 1;
    for(int i = 0 ; i < n ; ++i){
        int x;
        cin >> x;
        update(1 , 0 , N - 1 , beg + i , x);
    }
    int q;
    cin >> q;
    while(q--){
        int o;
        cin >> o;
        if(o == 1){
            int l , r;
            cin >> l >> r;
            int newL = beg + (l - 1) , newR = beg + (r - 1);
            cout << query(1 , 0 , N - 1 , newL , newR) << '\n';
        }
        else{
            int x;
            cin >> x;
            update(1 , 0 , N - 1 , --beg , x);
        }
    }
}
