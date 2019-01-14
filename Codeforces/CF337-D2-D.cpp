/*
    first lets choose arbitrary node as a root
    for each node we store max distance for an affected node in its subtree
    and max distance for an affected node not in its subtree
    we can solve first task by simple dfs and second task needs to re-calculate parent information
*/
#include <bits/stdc++.h>

#define pb push_back
#define all(v) (v).begin() , (v).end()
#define popcnt(x) __builtin_popcount(x)
#define inf 0x3f3f3f3f
#define watch(x) cout << (#x) << " is " << (x) << endl

using namespace std;
typedef long long  ll;
const int N = 1e5 + 4;

vector<int> adj[N];
multiset<int> pool[N];
int mx_down[N] , mx_up[N] , n , m , d;
bool is_damaged[N];

void pre_dfs(int node , int par){
    mx_down[node] = (is_damaged[node] ? 0 : mx_down[node]);
    for(int child : adj[node]){
        if(child == par)
            continue;
        pre_dfs(child , node);
        pool[node].insert(mx_down[child] + 1);
        mx_down[node] = max(mx_down[node] , mx_down[child] + 1);
    }
}

void dfs(int node , int par){
    mx_up[node] = (is_damaged[node] ? 0 : mx_up[node]);
    if(~par){
        pool[par].erase(pool[par].find(mx_down[node] + 1));
        if(pool[par].size())mx_up[node] = max(mx_up[node] , *pool[par].rbegin() + 1);
        pool[par].insert(mx_down[node] + 1);
        mx_up[node] = max(mx_up[node] , mx_up[par] + 1);
    }

    for(int child : adj[node]){
        if(child == par)
            continue;
        dfs(child , node);
    }
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);
    cin >> n >> m >> d;
    for(int i = 0 ; i < m ; ++i){
        int x;
        cin >> x;
        is_damaged[x] = true;
    }

    for(int i = 0 ; i < n - 1 ; ++i){
        int u , v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    memset(mx_down , -inf , sizeof mx_down);
    memset(mx_up , -inf , sizeof mx_up);
    pre_dfs(1 , 1);
    dfs(1 , -1);

    int cnt = 0;
    for(int i = 1 ; i <= n ; ++i)
        cnt += (mx_down[i] <= d && mx_up[i] <= d);

    cout << cnt << '\n';
}
