/*
    we need to count all combinations that satisfy
    bipartite graph constraints(no two adjacent nodes have the same colour)
    using dp we can solve this problem
*/
#include <bits/stdc++.h>
#define pb push_back
#define all(v) (v).begin() , (v).end()
#define popcnt(x) __builtin_popcount(x)
#define inf 0x3f3f3f3f
#define watch(x) cout << (#x) << " is " << (x) << endl
#define F first
#define S second

using namespace std;
typedef long long  ll;
const int N = 14;

int n;
vector<int> adj[N] , c[N];
ll memo[N][(1 << N) + 4][N * 8 + 4];
int cc = 0;

ll solve(int node , int msk , int lstcol){
    if(popcnt(msk) == cc)
        return 1;

    ll &ret = memo[node][msk][lstcol + 1];
    if(~ret)
        return ret;

    ret = 0;
    for(int child : adj[node]){
        if(!(msk & (1 << child))){
            for(int col : c[child]){
                if(col != lstcol)ret += solve(child , msk | (1 << child) , col);
            }
        }
    }
    return ret;
}

bool vis[N];

int dfs(int node){
    vis[node] = true;
    int ret = 1;
    for(int child : adj[node])
        if(!vis[child])ret += dfs(child);
    return ret;
}

void compress(){
    vector<int> compressed;
    for(int i = 1 ; i <= n ; ++i){
        for(int x : c[i])
            compressed.pb(x);
    }
    sort(all(compressed));
    compressed.resize(unique(all(compressed)) - compressed.begin());

    for(int i = 1 ; i <= n ; ++i){
        for(int &x : c[i])
            x = lower_bound(all(compressed) , x) - compressed.begin();
    }
}

void init(){
    for(int i = 0 ; i < N ; ++i)
        adj[i].clear() , c[i].clear();
    memset(vis , false , sizeof vis);
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r" , stdin);
#endif
    ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        init();
        cin >> n;
        if(n == 0){
            cout << 0 << '\n';
            continue;
        }
        for(int i = 1 ; i <= n ; ++i){
            for(int j = 1 ; j <= n ; ++j){
                char x;
                cin >> x;
                if(x == 'Y')adj[i].pb(j);
            }
        }

        for(int i = 1 ; i <= n ; ++i){
            int sz;
            cin >> sz;
            for(int j = 0 ; j < sz; ++j){
                int x;
                cin >> x;
                c[i].pb(x);
            }
        }

        compress();
        memset(memo , -1 , sizeof memo);
        ll ans = 1;

        for(int i = 1 ; i <= n ; ++i){
            if(vis[i])continue;
            cc = dfs(i);
            ll cur = 0;
            for(int col : c[i])
                cur += solve(i , (1 << i) , col);
            ans *= cur;
        }
        cout << ans << '\n';
    }
    return 0;
}
