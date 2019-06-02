#include <bits/stdc++.h>
#define pb push_back
#define all(v) (v).begin() , (v).end()
#define popcnt(x) __builtin_popcount(x)
#define inf 0x3f3f3f3f
#define watch(x) cout << (#x) << " is " << (x) << endl
#define rand() (rand() << 15 | rand())
using namespace std;
typedef long long  ll;
const double EPS = 1e-9;
const int N = 26;
int n;
double memo[2 * N][N] , p;


double solve(int matches , int wins){
    if(matches - wins == n)return 0.0;
    if(wins == n)return 1.0;

    double &ret = memo[matches][wins];
    if(ret == ret)
        return ret;

    ret = 0.0;
    ret += (p * solve(matches + 1 , wins + 1));
    ret += ((1 - p) * solve(matches + 1 , wins));
    return ret;
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt" , "r" , stdin);
#endif
    ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        cin >> n >> p;
        memset(memo , -1 , sizeof memo);
        cout << fixed << setprecision(2) << solve(0 , 0) + EPS << "\n";
    }
}
