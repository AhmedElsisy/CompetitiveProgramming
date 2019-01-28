/*
    segment tree to answer query and update in log2(n)
    let sz be the number of shifted numbers
    shift update -> iterate over the shifted indexes and update shifted[i] by value of shifted[(i + 1) % sz]
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


int a[N] , st[4 * N] , n , m;

int update(int p , int l , int r , int indx , int val){
    if(indx > r || indx < l)
        return st[p];
    if(l == r)
        return st[p] = a[l] = val;

    int mid = (l + r) >> 1;
    int p1 = update(p * 2 , l , mid , indx , val);
    int p2 = update(p * 2 + 1 , mid + 1 , r , indx , val);
    return st[p] = min(p1 , p2);
}

int query(int p , int l , int r , int i , int j){
    if(i > r || j < l)
        return inf;
    if(l >= i && r <= j)
        return st[p];

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
    scanf("%d %d" , &n , &m);
    for(int i = 0 ; i < n ; ++i)
        scanf("%d" , a + i) , update(1 , 0 , n - 1 , i , a[i]);

    while(m--){
        char tmp[34];
        scanf("%s" , tmp);
        string s = tmp;
        stringstream ss;
        ss << s;

        if(s[0] == 'q'){
            char x;
            while(true){
                ss >> x;
                if(x == '(')break;
            }
            int l , r;
            ss >> l >> x >> r >> x;
            printf("%d\n" , query(1 , 0 , n - 1 , l - 1 , r - 1));
        }
        else{
            char x;
            while(true){
                ss >> x;
                if(x == '(')break;
            }
            vector<int> v;
            int k;
            while(true){
                ss >> k;
                v.pb(k);
                ss >> x;
                if(x == ')')break;
            }

            int f = a[v[0] - 1];
            for(int i = 0 ; i + 1 < (int)v.size() ; ++i){
                int ind = v[i] - 1 , indpOne = v[i + 1] - 1;
                update(1 , 0 , n - 1 , ind , a[indpOne]);
            }
            update(1 , 0 , n - 1 , v[(int)v.size() - 1] - 1 , f);
        }
    }
}
