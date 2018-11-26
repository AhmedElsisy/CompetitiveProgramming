/*
    let h[x] be number of subtrees have x leafs
    we can calulate h[] using simple dfs
    and using prefix sum on h[]
    we can calculate minimum different colors 
    to make >= i happy junctions by lowerbound
    total complexity : O(n log n)
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
const int N = 1e5 + 4;

vector<int> adj[N];
int h[N] , sz[N];

int dfs(int node = 1 , int par = -1){
    sz[node] = 0;
    bool isleaf = true;
    for(int child : adj[node]){
        if(child != par){
            isleaf = false;
            sz[node] += dfs(child , node);
        }
    }
    if(isleaf)sz[node] = 1;
    h[sz[node]]++;
    return sz[node];
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r" , stdin);
#endif
    ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);
    int n;
    cin >> n;

    for(int i = 2 ; i <= n ; ++i){
        int p;
        cin >> p;
        adj[i].pb(p);
        adj[p].pb(i);
    }

    dfs();
    partial_sum(h , h + n + 1 , h);

    for(int i = 1 ; i <= n ; ++i)
        cout << lower_bound(h , h + n + 1 , i) - h << ' ';
    cout << '\n';
    return 0;
}
