/*
    first observation you are looking for max size of segment(l , r) such that gcd(l , r) == min(l , r)
    binary search the maximum size of segment and the validation will be done using sliding window
    you have segment size and you are looking for any segment with the criteria mentioned above
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


const int N = 3e5 + 4 , LG = log2(N) + 1;
int gcd[N][LG] , mn[N][LG];
int n , getlg[N];
vector<int> a;
// take care of long long

void pre(){
    for(int i = 1 ; i < N ; ++i)
        getlg[i] = (int)log2(i);
}

void build_gcd(){
    int lg = getlg[n];

    for(int i = 0 ; i < n ; ++i)
        gcd[i][0] = a[i];           // base case

    for(int j = 1 ; j <= lg ; ++j){
        for(int i = 0 ; i + (1 << j) - 1 < n ; ++i){
            gcd[i][j] = __gcd(gcd[i][j - 1] , gcd[i + (1 << (j - 1))][j - 1]);
        }
    }

}

void build_min(){
    int lg = getlg[n];

    for(int i = 0 ; i < n ; ++i)
        mn[i][0] = a[i];

    for(int j = 1 ; j <= lg ; ++j){
        for(int i = 0 ; i + (1 << j) - 1 < n ; ++i){
            mn[i][j] = min(mn[i][j - 1] , mn[i + (1 << (j - 1))][j - 1]);
        }
    }

}

int getmin(int l , int r){
    int sz = r - l + 1 , lg = getlg[sz] , dif = sz - (1 << lg);
    return min(mn[l][lg] , mn[l + dif][lg]);
}

int getGCD(int l , int r){          // query in log(N) s.t. N = max(gcd[l][lg] , gcd[l + dif][lg])
    int sz = r - l + 1 , lg = getlg[sz] , dif = sz - (1 << lg);
    return __gcd(gcd[l][lg] , gcd[l + dif][lg]);
}

bool valid(int mid){
    int i = 0 , j = mid - 1;
    while(j < n){
        if(getmin(i , j) == getGCD(i , j))return true;
        ++i , ++j;
    }
    return false;
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt" , "r" , stdin);
#endif
    ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);
    cin >> n;
    a.resize(n);
    for(int &x : a)
        cin >> x;

    pre();
    build_gcd();
    build_min();
    int l = 0 , r = n , ans = 1;
    while(l <= r){
        int mid = (l + r) >> 1;
        if(valid(mid))ans = mid , l = mid + 1;
        else r = mid - 1;
    }

    vector<int> res;
    for(int i = 0 ; i + ans - 1 < n ; ++i){
        if(getmin(i , i + ans - 1) == getGCD(i , i + ans - 1)){
            res.push_back(i + 1);
        }
    }

    cout << (int)res.size() << ' ' << ans - 1 << "\n";
    for(int x : res)
        cout << x << ' ';
    cout << "\n";
}
