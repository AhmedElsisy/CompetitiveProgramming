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
    int t , cs = 1;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<vector<int> > dp(n , vector<int>(n , inf));
        vector<vector<bool> > good(n , vector<bool>(n , false));
        for(int i = 0 ; i < n ; ++i)
            dp[i][i] = 0;
        for(int i = 1 ; i < n ; ++i){
            for(int j = 0 ; j < i ; ++j){
                int cost;
                cin >> cost;
                dp[i][j] = dp[j][i] = cost;
            }
        }

        for(int k = 0 ; k < n ; ++k){
            for(int i = 0 ; i < n ; ++i){
                for(int j = 0 ; j < n ; ++j){
                    if(k == i || k == j)continue;
                    if(dp[i][j] == dp[i][k] + dp[k][j]){
                        good[i][j] = true;
                    }
                }
            }
        }
        // now we know the actual edges in the graph G
        // lets run floyd warshal on it to detect whether all shortest paths are correct or not
        vector<vector<int> > dp2(n , vector<int>(n , inf));
        for(int i = 0 ; i < n ; ++i)
            dp2[i][i] = 0;
        for(int i = 0 ; i < n ; ++i){
            for(int j = 0 ; j < n ; ++j){
                if(!good[i][j]){
                    dp2[i][j] = dp[i][j];
                }
            }
        }

        for(int k = 0 ; k < n ; ++k){
            for(int i = 0 ; i < n ; ++i){
                for(int j = 0 ; j < n ; ++j){
                    dp2[i][j] = min(dp2[i][j] , dp2[i][k] + dp2[k][j]);
                }
            }
        }
        cout << "Case #" << cs++ << ":\n";
        if(dp != dp2){
            cout << "Need better measurements.\n";
        }
        else{
            vector<pair<pair<int , int> , int> > res;
            for(int i = 0 ; i < n ; ++i){
                for(int j = 0 ; j < n ; ++j){
                    if(!good[i][j] && i != j){
                        res.pb({{i + 1 , j + 1} , dp[i][j]});
                        good[j][i] = true;
                    }
                }
            }

            cout << (int)res.size() << "\n";
            for(auto e : res)
                cout << e.first.first << ' ' << e.first.second << ' ' << e.second << "\n";
        }
        cout << "\n";
    }
}
