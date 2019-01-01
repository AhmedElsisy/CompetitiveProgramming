#include <iostream>
#include <cstring>
#define pb push_back
#define all(v) (v).begin() , (v).end()
#define popcnt(x) __builtin_popcount(x)
#define inf 0x3f3f3f3f
#define watch(x) cout << (#x) << " is " << (x) << endl

using namespace std;
typedef long long  ll;
const int N = 304;
int n , k , a[304] , dp[N][34];
int cost[N][N];

int d(int i , int j){
    return abs(a[i] - a[j]);
}

void pre(){

    for(int i = 1 ; i <= n ; ++i){
        for(int j = i + 1 ; j <= n ; ++j){
            cost[i][j] = 0;
            for(int m = i ; m < j ; ++m){
                cost[i][j] += (d(m , i) < d(m , j) ? d(m , i) : d(m , j));
            }
        }
    }

    for(int i = 1 ; i <= n ; ++i){
        dp[i][1] = 0;
        for(int j = 1 ; j < i ; ++j){
            dp[i][1] += d(i , j);
        }
    }
}

int main() {
//    freopen("input.txt" , "r" , stdin);
    cin >> n >> k;
    for(int i = 1 ; i <= n ; ++i)
        cin >> a[i];
    pre();

    for(int i = 1 ; i <= n ; ++i){
        for(int j = 2 ; j <= k ; ++j){
            dp[i][j] = dp[i - 1][j - 1];
            for(int m = 1 ; m <= i - 2 ; ++m){
                dp[i][j] = min(dp[i][j] , dp[m][j - 1] + cost[m][i]);
            }
        }
    }

    int ret = inf;
    for(int i = 1 ; i <= n ; ++i){
        int cur = dp[i][k];
        for(int j = i + 1 ; j <= n ; ++j){
            cur += d(i , j);
        }
        ret = min(ret , cur);
    }

    cout << ret << '\n';
}
