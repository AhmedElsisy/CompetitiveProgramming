#include <bits/stdc++.h>
#define pb push_back
#define all(v) (v).begin() , (v).end()
#define popcnt(x) __builtin_popcount(x)
#define inf 0x3f3f3f3f
#define watch(x) cout << (#x) << " is " << (x) << endl
#define rand() (rand() << 15 | rand())

using namespace std;
typedef long long  ll;
const int N = 103 , M = (1 << 20);

int n , m , b;
long long dp[2][M];
struct P{
    int x , k , msk;
    bool operator < (const P & other) const{
        return k < other.k;
    }
}items[N];
int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt" , "r" , stdin);
#endif
    ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);
    cin >> n >> m >> b;
    items[0].k = 0;
    for(int i = 1 ; i <= n ; ++i){
        int sz;
        cin >> items[i].x >> items[i].k >> sz;
        while(sz--){
            int bit;
            cin >> bit;
            --bit;
            items[i].msk |= (1 << bit);
        }
    }

    sort(items + 1 , items + n + 1);

    for(int j = 0 ; j < M ; ++j){
        if(j != (1 << m) - 1)
            dp[0][j] = LLONG_MAX / 2;
    }

    long long res = LLONG_MAX / 2;
    for(int i = 1 ; i <= n ; ++i){
        for(int j = 0 ; j < M ; ++j){
            long long add = 1ll * items[i].k * b;
            dp[i & 1][j] = min(dp[(i - 1) & 1][j] , dp[(i - 1) & 1][j | items[i].msk] + items[i].x);
            if(!j){
                res = min(res , dp[i & 1][j] + add);
            }
        }
    }
    cout << (res >= LLONG_MAX / 2 ? -1 : res) << "\n";
}
