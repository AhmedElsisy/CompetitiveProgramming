#include <bits/stdc++.h>
#define pb push_back
#define all(v) (v).begin() , (v).end()
#define popcnt(x) __builtin_popcount(x)
#define inf 0x3f3f3f3f
#define watch(x) cout << (#x) << " is " << (x) << endl
#define rand() (rand() << 15 | rand())
using namespace std;
typedef long long  ll;
const int N = 53 , M = 100004;
vector<int> path , _costs;
int memo[N][M];

int solve(int indx , int rem){
    if(indx == (int)_costs.size() - 1)
        return (rem == _costs[indx] ? 1 : inf);

    int &ret = memo[indx][rem];
    if(~ret)
        return ret;

    ret = inf;
    if(rem >= _costs[indx]){
        if(rem >= 2 * _costs[indx])ret = min(ret , 2 + solve(indx , rem - 2 * _costs[indx]));
        ret = min(ret , 1 + solve(indx + 1 , rem - _costs[indx]));
    }
    return ret;
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt" , "r" , stdin);
#endif
//    ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n , m;
        cin >> n >> m;
        vector<vector<int> > dp(n + 1 , vector<int>(n + 1 , inf));
        for(int i = 0 ; i < m ; ++i){
            int u , v , c;
            cin >> u >> v >> c;
            dp[u][v] = dp[v][u] = c;
        }
        vector<vector<int> > par(n + 1 , vector<int>(n + 1 , -1));
        for(int i = 1 ; i <= n ; ++i){
            for(int j = 1 ; j <= n ; ++j){
                par[i][j] = i;
            }
        }
        for(int i = 1 ; i <= n ; ++i){
            for(int j = 1 ; j <= n ; ++j){
                for(int k = 1 ; k <= n ; ++k){
                    if(dp[i][j] > dp[i][k] + dp[k][j]){
                        dp[i][j] = dp[i][k] + dp[k][j];
                        par[i][j] = par[k][j];
                    }
                }
            }
        }


        int q;
        cin >> q;
        while(q--){
            int u , v , cost;
            cin >> u >> v >> cost;
            path.clear();
            memset(memo , -1 , sizeof memo);
            if(dp[u][v] >= inf || u == v)
                cout << "No\n";
            else{
                int i = u , j = v;
                while(j != i){
                    path.pb(j);
                    j = par[i][j];
                }
                path.pb(i);
                _costs.clear();
                reverse(all(path));
                for(int i = 0 ; i + 1 < (int)path.size() ; ++i){
                    _costs.pb(dp[path[i]][path[i + 1]]);
                }

                int res = solve(0 , cost);
                if(res >= inf)
                    cout << "No\n";
                else
                    cout << "Yes " << res << "\n";
            }
        }
        if(t)cout << endl;
    }
}
