/*
    let gcd(i , j) be the gcd of all elements in range [i , j].
    the key idea of this problem that the value that if you choose i as a beginning of a sub-array
    and the current gcd is a[i] , then you have at most log2(a[i]) different indexes the value of current gcd will decrease
    for each gcd you want to know longest sub-array(i , j) that gcd(i , j) is equal to gcd
    then the complexity : O(n * log2(n) * log2(1e12)) in worst case
*/

#include <bits/stdc++.h>
#define pb push_back
#define all(v) (v).begin() , (v).end()
#define popcnt(x) __builtin_popcount(x)
#define inf 0x3f3f3f3f
#define watch(x) cout << (#x) << " is " << (x) << endl

using namespace std;
typedef long long  ll;

const int N = 1e5 + 4 , LG = log2(N) + 1;
ll gcd[N][LG];
int n , getlg[N];
vector<ll> a;

void build(){
    int lg = getlg[n];

    for(int i = 0 ; i < n ; ++i)
        gcd[i][0] = a[i];           // base case

    for(int j = 1 ; j <= lg ; ++j){
        for(int i = 0 ; i + (1 << j) - 1 < n ; ++i){
            gcd[i][j] = __gcd(gcd[i][j - 1] , gcd[i + (1 << (j - 1))][j - 1]);
        }
    }

}

ll getGCD(int l , int r){
    int sz = r - l + 1 , lg = getlg[sz] , dif = sz - (1 << lg);
    return __gcd(gcd[l][lg] , gcd[l + dif][lg]);
}

void pre(){
    for(int i = 1 ; i < N ; ++i)
        getlg[i] = (int)log2(i);
}

bool valid(int l , int r , ll v){
    return getGCD(l , r) == v;
}

int main() {
    ios::sync_with_stdio() , cin.tie(0) , cin.tie(0);
    pre();
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        a.resize(n);
        for(ll &x : a)
            cin >> x;

        build();
        ll mx = 0;
        for(int i = 0 ; i < n ; ++i){
            ll curGCD = a[i] , nxtGCD = a[i];
            int j = i;
            while(true){

                int l = j , r = n - 1 , ans = -1;
                while(l <= r){
                    int mid = (l + r) >> 1;

                    if(valid(i , mid , curGCD)){
                        ans = mid;
                        l = mid + 1;
                    }
                    else nxtGCD = getGCD(i , mid) , j = mid , r = mid - 1;
                }

                if(ans == -1)break;
                mx = max(mx , 1ll * (ans - i + 1) * curGCD);
                if(curGCD == nxtGCD)break;
                curGCD = nxtGCD;
            }

        }

        cout << mx << '\n';
    }
}
