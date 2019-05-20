#include <bits/stdc++.h>
#define pb push_back
#define all(v) (v).begin() , (v).end()
#define popcnt(x) __builtin_popcount(x)
#define inf 0x3f3f3f3f
#define watch(x) cout << (#x) << " is " << (x) << endl
#define rand() (rand() << 15 | rand())
using namespace std;
typedef long long  ll;

struct Edge{
    int u , v;
};
int n , m;

vector<vector<int> > getAdjList(vector<Edge> &v){
    vector<vector<int> > adj(n + 1 , vector<int>());
    for(auto e : v){
        adj[e.u].pb(e.v);
        adj[e.v].pb(e.u);
    }
    return adj;
}

vector<vector<int> > adj;
vector<Edge> goodEdges;
vector<bool> good;

bool dfs(int u , int p){
    bool ok = good[u];
    for(int v : adj[u]){
        if(v != p){
            if(dfs(v , u)){
                ok = true;
                goodEdges.pb({u , v});
            }
        }
    }
    return ok;
}

vector<int> height;
int theOne = -1;

void dfs2(int u , int p , int d){
    height[u] = d;
    for(int v : adj[u]){
        if(v != p){
            dfs2(v , u , d + 1);
        }
    }
}
int getDiameter(int u){
    height.assign(n + 1 , -1);
    dfs2(u , u , 0);
    int mx = *max_element(all(height)) , v = inf;
    for(int i = 1 ; i <= n ; ++i){
        if(height[i] == mx)v = min(v , i);
    }
    height.assign(n + 1 , -1);
    dfs2(v , v , 0);
    mx = *max_element(all(height));
    for(int i = 1 ; i <= n ; ++i){
        if(height[i] == mx)v = min(v , i);
    }
    theOne = v;
    return mx;
}
int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt" , "r" , stdin);
#endif
    ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);
    cin >> n >> m;
    good.assign(n + 1 , false);
    vector<Edge> v;
    for(int i = 0 ; i < n - 1 ; ++i){
        Edge e;
        cin >> e.u >> e.v;
        v.pb(e);
    }

    vector<int> goodcities;
    for(int i = 0 ; i < m ; ++i){
        int u;
        cin >> u;
        good[u] = true;
        goodcities.pb(u);
    }
    adj = getAdjList(v);
    dfs(goodcities[0] , -1);
    adj = getAdjList(goodEdges);

    int len = 2 * (int)goodEdges.size();
    len -= getDiameter(goodcities[0]);

    cout << theOne << "\n" << len << "\n";
}
