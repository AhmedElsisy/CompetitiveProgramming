#include <bits/stdc++.h>
#define pb push_back
#define all(v) (v).begin() , (v).end()
#define popcnt(x) __builtin_popcount(x)
#define inf 0x3f3f3f3f
#define watch(x) cout << (#x) << " is " << (x) << endl
#define rand() (rand() << 15 | rand())

using namespace std;
typedef long long  ll;
typedef long double  ld;

const int N = 1e3 + 4;
vector<int> adj[N] , match , vis;
int n , m , vid = 1;

int dfs(int u){
    if(vis[u] == vid)
        return 0;
    vis[u] = vid;
    for(int v : adj[u]){
        if(match[v] == -1 || dfs(match[v])){
            match[v] = u;
            return 1;
        }
    }
    return 0;
}

int MCBM(){
    match.assign(n + 1 , -1);
    vis.assign(n + 1 , 0);
    int ret = 0;
    for(int i = 1 ; i <= n ; ++i){    // 1 - based
        if(dfs(i))++ret;
        ++vid;
    }
    return ret;
}

/*
6 5
1 6
2 4
3 6
2 5
1 4
*/

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt" , "r" , stdin);
#endif
    ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);
    cin >> n >> m;
    for(int i = 0 ; i < m ; ++i){   // take care of the labels numbers of the nodes
        int u , v;
        cin >> u >> v;
        adj[u].pb(v);
    }

    cout << MCBM() << endl;
}
