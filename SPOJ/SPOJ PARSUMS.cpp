/*
    let iterate over cycle shifts from 0 to n - 1
    for each cyclic shift we break down the array into two parts form 1 to i - 1 and i to n
    so for the second part all elements from i to n should be decreased by the sum of [1 : i - 1]
    and all elements from 1 to i - 1 should be increased by the new nth element
    and for every cyclic shift check for the property using min segment tree with lazy for updates
*/

#include <bits/stdc++.h>

#define pb push_back
#define all(v) (v).begin() , (v).end()
#define popcnt(x) __builtin_popcount(x)
#define inf 0x3f3f3f3f
#define watch(x) cout << (#x) << " is " << (x) << endl

using namespace std;
typedef long long  ll;
const int N = 1e6 + 4;

int a[N] , st[4 * N] , lz[4 * N];

void build(int p , int l , int r){
    if(l == r){
        st[p] = a[l];
        lz[p] = 0;
        return;
    }
    int mid = (l + r) >> 1;
    build(p * 2 , l , mid);
    build(p * 2 + 1 , mid + 1 , r);
    st[p] = min(st[p * 2] , st[p * 2 + 1]);
}

void propagate(int p){
    if(!lz[p])return;
    st[2 * p] += lz[p];
    st[2 * p + 1] += lz[p];
    lz[2 * p] += lz[p];
    lz[2 * p + 1] += lz[p];
    lz[p] = 0;
}

int update(int p , int l , int r , int i , int j , int val){
    if(l > j || r < i)
        return st[p];
    if(l >= i && r <= j){
        st[p] += val;
        lz[p] += val;
        return st[p];
    }

    propagate(p);
    int mid = (l + r) >> 1;
    int p1 = update(p * 2 , l , mid , i , j , val);
    int p2 = update(p * 2 + 1 , mid + 1 , r , i , j , val);
    return st[p] = min(p1 , p2);
}

int query(int p , int l , int r , int i , int j){
    if(l > j || r < i)
        return inf;
    if(l >= i && r <= j)
        return st[p];

    propagate(p);
    int mid = (l + r) >> 1;
    int p1 = query(p * 2 , l , mid , i , j);
    int p2 = query(p * 2 + 1 , mid + 1 , r , i , j);
    return min(p1 , p2);
}


int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt" , "r" , stdin);
#endif
    ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);
    int n;
    while(cin >> n && n){
        for(int i = 1 ; i <= n ; ++i){
            cin >> a[i];
            a[i] += a[i - 1];
        }

        build(1 , 1 , n);

        int cnt = 0;
        for(int i = 1 ; i <= n ; ++i){
            int add_right = a[i - 1];
            update(1 , 1 , n , i , n , -add_right);
            int add_left = query(1 , 1 , n , n , n);
            if(i > 1)update(1 , 1 , n , 1 , i - 1 , add_left);
//            watch(query(1 , 1 , n , 1 , n));
            cnt += (query(1 , 1 , n , 1 , n) >= 0);
            if(i > 1)update(1 , 1 , n , 1 , i - 1 , -add_left);
            update(1 , 1 , n , i , n , add_right);
        }
        cout << cnt << '\n';
    }
}
