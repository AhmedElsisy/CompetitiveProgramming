#include <bits/stdc++.h>
#define pb push_back
#define all(v) (v).begin() , (v).end()
#define popcnt(x) __builtin_popcount(x)
#define inf 0x3f3f3f3f
#define watch(x) cout << (#x) << " is " << (x) << endl
#define rand() (rand() << 15 | rand())
using namespace std;
typedef long long  ll;
const int N = 103;

vector<int> adj[N];
int col[N];

void dfs(int u , int c){
    col[u] = c;
    for(int v : adj[u]){
        if(col[v] == -1)
            dfs(v , !c);
    }
}
int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt" , "r" , stdin);
#endif
    ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);
    int t , cs = 1;
    cin >> t;
    while(t--){
        int n , m;
        cin >> n >> m;
        for(int i = 0 ; i <= n ; ++i)
            adj[i].clear();
        for(int i = 0 ; i < m ; ++i){
            int u , v;
            cin >> u >> v;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        memset(col , -1 , sizeof col);
        for(int i = 1 ; i <= n ; ++i){
            if(col[i] == -1)
                dfs(i , 0);
        }

        vector<int> res;
        for(int i = 1 ; i <= n ; ++i){
            if(col[i] == 1)
                res.pb(i);
        }

        cout << "Case #" << cs++ << ": " << res.size() << "\n";
        for(int x : res)
            cout << x << ' ';
        cout << "\n";

    }
}
