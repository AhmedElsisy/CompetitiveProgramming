#include <bits/stdc++.h>
#define pb push_back
#define all(v) (v).begin() , (v).end()
#define popcnt(x) __builtin_popcount(x)
#define inf 0x3f3f3f3f
#define watch(x) cout << (#x) << " is " << (x) << endl
#define rand() (rand() << 15 | rand())

using namespace std;
typedef long long  ll;
const int N = 54;

int memo[N][N] , l , n;
vector<int> a;

int solve(int i , int j){
    if(j - i < 2)
        return 0;

    int &ret = memo[i][j];
    if(~ret)
        return ret;

    ret = inf;
    for(int k = i ; k <= j; ++k){
        int cost = a[j] - a[i];
        ret = min(ret , cost + solve(i , k) + solve(k , j));
    }
    return ret;
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt" , "r" , stdin);
#endif
    ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);
    while(cin >> l && l){
        a.clear();
        cin >> n;
        a.pb(0);
        for(int i = 0 ; i < n ; ++i){
            int x;
            cin >> x;
            a.pb(x);
        }
        a.pb(l);

        memset(memo , -1 , sizeof memo);

        printf("The minimum cutting is %d.\n" , solve(0 , (int)a.size() - 1));
    }
}
