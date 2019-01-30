/*
    the main idea is how to add x into segment you store only the sum of square for the elements
    so (a + x)^2 = a^2 + 2ax + x^2 = a^2 + x(2a + x) - (you can derive the used formula from this observation)
    the rest of the problem is how to store lazy propagation value and this simple to track it
*/

#include <bits/stdc++.h>

#define pb push_back
#define all(v) (v).begin() , (v).end()
#define popcnt(x) __builtin_popcount(x)
#define inf 0x3f3f3f3f
#define watch(x) cout << (#x) << " is " << (x) << endl

using namespace std;
typedef long long  ll;
const int N = 1e5 + 4;

ll a[N];
pair<ll , ll> st[4 * N];
ll lz_put[4 * N] , lz_add[4 * N];

void renew(int p , int l , int r , ll val){
    st[p].first = st[p].first + val * ((2 * st[p].second) + val * (r - l + 1));
    st[p].second += val * (r - l + 1);
}

void propagate(int p , int l , int r){
    if(!lz_add[p] && !lz_put[p])return;

    int mid = (l + r) >> 1;
    if(lz_put[p]){
        lz_add[2 * p] = lz_add[2 * p + 1] = 0;
        st[2 * p].first = 1ll * (mid - l + 1) * (lz_put[p] * lz_put[p]);
        st[2 * p].second = 1ll * (mid - l + 1) * (lz_put[p]);
        st[2 * p + 1].first = 1ll * (r - mid - 1 + 1) * (lz_put[p] * lz_put[p]);
        st[2 * p + 1].second = 1ll * (r - mid - 1 + 1) * (lz_put[p]);
        lz_put[2 * p] = lz_put[2 * p + 1] = lz_put[p];
        renew(2 * p , l , mid , lz_add[p]);
        renew(2 * p + 1 , mid + 1 , r , lz_add[p]);
        lz_add[2 * p] += lz_add[p];
        lz_add[2 * p + 1] += lz_add[p];
    }
    else{
        renew(2 * p , l , mid , lz_add[p]);
        renew(2 * p + 1 , mid + 1 , r , lz_add[p]);
        lz_add[2 * p] = lz_add[2 * p + 1] = lz_add[p];
    }
    lz_put[p] = lz_add[p] = 0;
}

void build(int p , int l , int r){
    lz_add[p] = lz_put[p] = 0;
    if(l == r){
        st[p].first = a[l] * a[l];
        st[p].second = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(p * 2 , l , mid);
    build(p * 2 + 1 , mid + 1 , r);
    st[p].first = st[2 * p].first + st[2 * p + 1].first;
    st[p].second = st[2 * p].second + st[2 * p + 1].second;
}


pair<ll , ll> update(int p , int l , int r , int i , int j , ll val , int type){
    if(l > j || r < i)
        return st[p];
    if(l >= i && r <= j){
        if(type){ // add
            renew(p , l , r , val);
            lz_add[p] += val;
        }
        else{ // put
            lz_add[p] = 0;
            st[p].first = 1ll * (r - l + 1) * (val * val);
            st[p].second = 1ll * (r - l + 1) * val;
            lz_put[p] = val;
        }
        return st[p];
    }

    propagate(p , l , r);

    int mid = (l + r) >> 1;
    pair<ll , ll> p1 = update(p * 2 , l , mid , i , j , val , type);
    pair<ll , ll> p2 = update(p * 2 + 1 , mid + 1 , r , i , j , val , type);
    pair<ll , ll> ret;
    ret.first = p1.first + p2.first;
    ret.second = p1.second + p2.second;
    return st[p] = ret;
}

ll query(int p , int l , int r , int i , int j){
    if(r < i || l > j)
        return 0;
    if(l >= i && r <= j)
        return st[p].first;

    propagate(p , l , r);

    int mid = (l + r) >> 1;
    ll p1 = query(p * 2 , l , mid , i , j);
    ll p2 = query(p * 2 + 1 , mid + 1 , r , i , j);
    return p1 + p2;
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt" , "r" , stdin);
#endif
    int t , cs = 1;
    scanf("%d" , &t);
    while(t--){
        int n , q;
        scanf("%d %d" , &n , &q);
        for(int i = 0 ; i < n ; ++i)
            scanf("%d" , a + i);

        build(1 , 0 , n - 1);
        printf("Case %d:\n" , cs++);
        while(q--){
            int type , l , r;
            scanf("%d %d %d" , &type , &l , &r);
            --l , --r;
            if(type == 0){
                int x;
                scanf("%d" , &x);
                update(1 , 0 , n - 1 , l , r , x , type);
            }
            else if(type == 1){
                int x;
                scanf("%d" , &x);
                update(1 , 0 , n - 1 , l , r , x , type);
            }
            else{
                printf("%lld\n" , query(1 , 0 , n - 1 , l , r));
            }
        }

    }
}
