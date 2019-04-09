/*
    its easy to see that if we fix L then the maximum (L,R + 1) either increase or still the same related with (L,R)
    and the same with the minimum
    we can observe that if we fix L there is a continuous range(possible empty) will meet the conditions or not maxA = minB
    we only need to binary search that range(start , end) using a quick getting minimum and maximum with sparse table
*/

#include <bits/stdc++.h>
#define pb push_back
#define all(v) (v).begin() , (v).end()
#define popcnt(x) __builtin_popcount(x)
#define inf 0x3f3f3f3f
#define watch(x) cout << (#x) << " is " << (x) << endl
#define rand() (rand() << 15 | rand())

using namespace std;
typedef long long  ll;
const int N = 2e5 + 4 , LG = log2(N) + 1;
int mx[N][LG] , mn[N][LG];
int n , getlg[N];
vector<int> a , b;
void pre(){
    for(int i = 1 ; i < N ; ++i)
        getlg[i] = (int)log2(i);
}
void buildmx(){
    int lg = getlg[n];

    for(int i = 0 ; i < n ; ++i)
        mx[i][0] = a[i];

    for(int j = 1 ; j <= lg ; ++j){
        for(int i = 0 ; i + (1 << j) - 1 < n ; ++i){
            mx[i][j] = max(mx[i][j - 1] , mx[i + (1 << (j - 1))][j - 1]);
        }
    }

}

int getMx(int l , int r){
    int sz = r - l + 1 , lg = getlg[sz] , dif = sz - (1 << lg);
    return max(mx[l][lg] , mx[l + dif][lg]);
}

void buildmn(){
    int lg = getlg[n];

    for(int i = 0 ; i < n ; ++i)
        mn[i][0] = b[i];

    for(int j = 1 ; j <= lg ; ++j){
        for(int i = 0 ; i + (1 << j) - 1 < n ; ++i){
            mn[i][j] = min(mn[i][j - 1] , mn[i + (1 << (j - 1))][j - 1]);
        }
    }

}

int getMn(int l , int r){
    int sz = r - l + 1 , lg = getlg[sz] , dif = sz - (1 << lg);
    return min(mn[l][lg] , mn[l + dif][lg]);
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt" , "r" , stdin);
#endif
    ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);
    cin >> n;
    a.resize(n);
    b.resize(n);
    pre();
    for(int &x : a)
        cin >> x;
    for(int &x : b)
        cin >> x;

    buildmx();
    buildmn();
    ll ans = 0;
    for(int i = 0 ; i < n ; ++i){

        int l = i , r = n - 1 , L = -1 , R = -1;
        while(l <= r){
            int mid = (l + r) >> 1;
            int f1 = getMx(i , mid) , f2 = getMn(i , mid);

            if(f1 >= f2)
                L = mid , r = mid - 1;
            else l = mid + 1;
        }

        l = i , r = n - 1;
        while(l <= r){
            int mid = (l + r) >> 1;
            int f1 = getMx(i , mid) , f2 = getMn(i , mid);

            if(f1 > f2)
                r = mid - 1;
            else R = mid , l = mid + 1;
        }
        if(~L && ~R && getMn(i , L) == getMx(i , L))ans += R - L + 1;
    }
    cout << ans << "\n";
}
