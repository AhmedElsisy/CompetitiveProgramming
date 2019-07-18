#include <bits/stdc++.h>
#define pb push_back
#define all(v) (v).begin() , (v).end()
#define popcnt(x) __builtin_popcount(x)
#define inf 0x3f3f3f3f
#define watch(x) cout << (#x) << " is " << (x) << endl
#define rand() (rand() << 15 | rand())
using namespace std;
const int N = 1e5 + 4 , LG = log2(N) + 1;
int st[N][LG];
int n , getlg[N];
vector<int> a;
void pre(){
    for(int i = 1 ; i < N ; ++i)
        getlg[i] = (int)log2(i);
}
 
void build(){
    int lg = getlg[n];
 
    for(int i = 0 ; i < n ; ++i)
        st[i][0] = a[i];           // base case
 
    for(int j = 1 ; j <= lg ; ++j){
        for(int i = 0 ; i + (1 << j) - 1 < n ; ++i){
            st[i][j] = max(st[i][j - 1] , st[i + (1 << (j - 1))][j - 1]);
        }
    }
 
}
 
int getMX(int l , int r){
    int sz = r - l + 1 , lg = getlg[sz] , dif = sz - (1 << lg);
    return max(st[l][lg] , st[l + dif][lg]);
}
 
 
int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt" , "r" , stdin);
#endif
    ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);
    cin >> n;
    a.assign(n , 0);
    for(int &x : a)
        cin >> x;
    pre();
    build();
    int mx = 0;
    for(int i = 0 ; i < n ; ++i){
        int l = 0 , r = i - 1 , nxt = -1;
        while(l <= r){
            int mid = (l + r) >> 1;
            if(getMX(mid , i) > a[i])nxt = mid , l = mid + 1;
            else r = mid - 1;
        }
        if(~nxt)mx = max(mx , a[i] ^ a[nxt]);
 
        l = i + 1 , r = n - 1 , nxt = -1;
        while(l <= r){
            int mid = (l + r) >> 1;
            if(getMX(i , mid) > a[i])nxt = mid , r = mid - 1;
            else l = mid + 1;
        }
        if(~nxt)mx = max(mx , a[i] ^ a[nxt]);
    }
 
    cout << mx << "\n";
}
