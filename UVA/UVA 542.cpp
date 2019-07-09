#include <bits/stdc++.h>
#define pb push_back
#define all(v) (v).begin() , (v).end()
#define popcnt(x) __builtin_popcount(x)
#define inf 0x3f3f3f3f
#define watch(x) cout << (#x) << " is " << (x) << endl
#define rand() (rand() << 15 | rand())
using namespace std;
typedef long long  ll;

double dp[6][16] , p[16][16];

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt" , "r" , stdin);
#endif
    ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);
    vector<string> v(16);
    for(auto &s : v)
        cin >> s;

    for(int i = 0 ; i < 16 ; ++i){
        for(int j = 0 ; j < 16 ; ++j){
            cin >> p[i][j];
            p[i][j] /= 100.0;
        }
    }

    for(int i = 0 ; i < 16 ; ++i)
        dp[0][i] = 1.0;

    for(int i = 1 ; i < 5 ; ++i){
        for(int j = 0 ; j < 16 ; ++j){
            int l = (1 << i) * (j / (1 << i)) , r = (1 << i);
            for(int k = l ; (k - l) < r ; ++k){
                if((k / (1 << (i - 1))) == (j / (1 << (i - 1))))continue; // from the same branch i can't face him if i qualified to this round
                dp[i][j] += dp[i - 1][j] * p[j][k] * dp[i - 1][k];
            }
        }
    }

    for(int i = 0 ; i < 16 ; ++i)
        cout << setw(10) << left << v[i] << " p=" << fixed << setprecision(2) << dp[4][i] * 100.0 << "%\n";
}
