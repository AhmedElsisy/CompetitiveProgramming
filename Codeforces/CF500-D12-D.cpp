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
struct Edge{
    int u , v , w;
};
vector<int> adj[N];
vector<Edge> edgeList;
ll memo[N][4];

ll nCr(int n , int r){
    if(n < r)
        return 0;
    if(n == r)
        return 1;
    if(!r)
        return 1;
    ll &ret = memo[n][r];
    if(~ret)
        return ret;
    ret = 0;
    return ret = nCr(n - 1 , r - 1) + nCr(n - 1 , r);
}

int n;
map<pair<int , int> , ll> mp;
int sz[N];

int dfs(int node , int par){
    sz[node] = 1;
    for(auto child : adj[node]){
        if(child == par)continue;
        sz[node] += dfs(child , node);
        mp[{node , child}] = mp[{child , node}] = 2ll * (nCr(sz[child] , 2) * nCr(n - sz[child] , 1) +
                                           nCr(n - sz[child] , 2) * nCr(sz[child] , 1));
    }
    return sz[node];
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt" , "r" , stdin);
#endif
    ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);
    memset(memo , -1 , sizeof memo);
    cin >> n;
    for(int i = 0 ; i < n - 1 ; ++i){
        int u , v , w;
        cin >> u >> v >> w;
        edgeList.pb({u , v , w});
        adj[u].pb(v);
        adj[v].pb(u);
    }

    dfs(1 , 1);

    long double tot = 0;
    for(Edge e : edgeList)
        tot += 1ll * e.w * mp[{e.u , e.v}];

    // to avoid stack overflow of nCr recursive function
    for(int i = 1 ; i <= 100000 ; ++i)
        for(int j = 0 ; j <= 3 ; ++j)
            nCr(i , j);

    int q;
    cin >> q;
    while(q--){
        int indx , new_cost;
        cin >> indx >> new_cost;
        indx--;

        int old_cost = edgeList[indx].w;

        tot -= 1ll * old_cost * mp[{edgeList[indx].u , edgeList[indx].v}];
        tot += 1ll * new_cost * mp[{edgeList[indx].u , edgeList[indx].v}];
        edgeList[indx].w = new_cost;

        cout << fixed << setprecision(12) << 1.0 * tot / nCr(n , 3) << "\n";
    }
}
