#include <bits/stdc++.h>
#define pb push_back
#define all(v) (v).begin() , (v).end()
#define popcnt(x) __builtin_popcount(x)
#define inf 0x3f3f3f3f
#define watch(x) cout << (#x) << " is " << (x) << endl
#define rand() (rand() << 15 | rand())

using namespace std;
typedef long long  ll;

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt" , "r" , stdin);
#endif
    ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);
    int m , n;
    cin >> m >> n;
    double ans = 0.0;
    for(int side = 1 ; side <= m ; ++side){
        double pSide = pow(1.0 * side / m , n) - pow(1.0 * (side - 1) / m , n);
        ans += pSide * side;
    }
    cout << fixed << setprecision(10) << ans << "\n";
}
