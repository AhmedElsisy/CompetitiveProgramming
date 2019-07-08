#include <bits/stdc++.h>
#define pb push_back
#define all(v) (v).begin() , (v).end()
#define popcnt(x) __builtin_popcount(x)
#define inf 0x3f3f3f3f
#define watch(x) cout << (#x) << " is " << (x) << endl
#define rand() (rand() << 15 | rand())
using namespace std;
typedef long long  ll;
const int N = 1e5 + 4;
int dfs_num[N] , dfs_low[N] , timer = 0 , n , m;
bool vis[N];
vector<int> adj[N];
vector<pair<int , int> > Bridges;
// get Bridges in undirected graph
void dfs(int u , int p){
    dfs_num[u] = dfs_low[u] = timer++;
    vis[u] = true;
    for(int c : adj[u]){
        if(p == c)continue;
        if(!vis[c]){
            dfs(c , u);
            dfs_low[u] = min(dfs_low[u] , dfs_low[c]);
            if(dfs_low[c] > dfs_num[u]){
                Bridges.emplace_back(min(u , c) , max(u , c));
            }
        }
        else dfs_low[u] = min(dfs_low[u] , dfs_num[c]);
    }
}

void init(){
    for(int i = 0 ; i <= n ; ++i)
        adj[i].clear();
    memset(vis , false , sizeof vis);
    timer = 0;
    Bridges.clear();
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt" , "r" , stdin);
#endif
    ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);
    while(cin >> n){
        init();
        for(int i = 0 ; i < n ; ++i){
            int u;
            cin >> u;
            int sz;
            char c;
            cin >> c >> sz >> c;
            for(int j = 0 ; j < sz ; ++j){
                int v;
                cin >> v;
                adj[u].pb(v);
            }
        }

        for(int i = 0 ; i < n ; ++i)
            if(!vis[i])dfs(i , i);

        sort(all(Bridges));
        cout << (int)Bridges.size() << " critical links\n";
        for(auto e : Bridges){
            cout << e.first << " - " << e.second << "\n";
        }
        cout << endl;
    }
}
