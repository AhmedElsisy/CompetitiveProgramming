#include <bits/stdc++.h>
#define pb push_back
#define all(v) (v).begin() , (v).end()
#define popcnt(x) __builtin_popcount(x)
#define inf 0x3f3f3f3f
#define watch(x) cout << (#x) << " is " << (x) << endl
#define rand() (rand() << 15 | rand())
using namespace std;
typedef long long  ll;
const int N = 13;
int memo[N][1 << N] , n;

int solve(int indx , int msk){
    if(indx == n)
        return 1;
    int &ret = memo[indx][msk];
    if(~ret)
        return ret;

    ret = 0;
    for(int i = 0 ; i < n ; ++i){
        if(i == indx || msk & (1 << i))continue;
        ret += solve(indx + 1 , msk | (1 << i));
    }
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
        cin >> n;
        memset(memo , -1 , sizeof memo);
        int f = 1;
        for(int i = 1 ; i <= n ; ++i)f *= i;
        cout << solve(0 , 0) << '/' << f << "\n";
    }
}
