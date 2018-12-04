/*
    let connect (i , j) as an edge in a graph
    and run dfs traversal to insert all characters in each component in multiset
    then iterate on the string from i to n - 1 each character we pre-process in which component it is involved
    choose the minimum character of the component's multiset and erase it and so on
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
string s;
int n , c = 0;
int toCC[N];
vector<int> adj[N];
multiset<char> cc[N];
bool vis[N];

void init(){
    for(int i = 0 ; i < N ; ++i)adj[i].clear();
    memset(vis , 0 , sizeof vis);
    c = 0;
}

void dfs(int node){
    vis[node] = true;
    toCC[node] = c;
    cc[c].insert(s[node]);
    for(int child : adj[node])
        if(!vis[child])dfs(child);
}

int main() {
    ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        init();
        cin >> s >> n;

        while(n--){
            int u , v;
            cin >> u >> v;
            adj[u].pb(v);
            adj[v].pb(u);
        }

        for(int i = 0 ; i < (int)s.size() ; ++i)
            if(!vis[i])dfs(i) , c++;

        for(int i = 0 ; i < (int)s.size() ; ++i){
            s[i] = *cc[toCC[i]].begin();
            cc[toCC[i]].erase(cc[toCC[i]].begin());
        }

        cout << s << '\n';
    }
}
