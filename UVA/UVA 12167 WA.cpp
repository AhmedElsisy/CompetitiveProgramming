#include<bits/stdc++.h>
#define pb push_back
#define all(v) (v).begin() , (v).end()
#define popcnt(x) __builtin_popcount(x)
#define inf 0x3f3f3f3f
#define watch(x) cout << (#x) << " is " << (x) << endl
#define rand() (rand() << 15 | rand())
using namespace std;
typedef long long  ll;
const int N = 2e5 + 4;
int dfs_num[N] , dfs_low[N] , timer = 0 , n , m , cmp[N];
int indeg[N] , outdeg[N];
bool inStack[N] , vis[N];
stack<int> st;
vector<int> adj[N] , undir[N];
vector<vector<int> > comp;

void SCC(int u){                                // Strongly connected components in Directed Graph O(V + E)
    dfs_num[u] = dfs_low[u] = ++timer;
    inStack[u] = 1;
    vis[u] = true;
    st.push(u);
    for(int c : adj[u]){
        if(!vis[c]){
            SCC(c);
            dfs_low[u] = min(dfs_low[u] , dfs_low[c]);
        }
        else if(inStack[c])
            dfs_low[u] = min(dfs_low[u], dfs_num[c]);
    }
    if(dfs_num[u] == dfs_low[u]){
        comp.push_back({});
        while(1){
            int t = st.top();
            st.pop();
            inStack[t] = 0;
            cmp[t] = (int)comp.size() - 1;
            comp.back().push_back(t);
            if(t == u)break;
        }
    }
}
int cc = 0;
void init(){
    cc = 0;
    for(int i = 0 ; i <= n ; ++i)
        adj[i].clear() , undir[i].clear();
    memset(vis , false , sizeof vis);
    timer = 0;
    comp.clear();
    memset(indeg , 0 , sizeof indeg);
    memset(outdeg , 0 , sizeof outdeg);
}

void run(){                             // edit indexes of nodes (1 - based here)
    for(int i = 1 ; i <= n ; ++i){       // iterate over node to call SCC in every un-visted node
        if(!vis[i]){
            SCC(i);
        }
    }
}

int in = 0 , out = 0;
int go(int u){
    int ret = 1;
    vis[u] = true;
    in += (indeg[u] == 0);
    out += (outdeg[u] == 0);
    for(int c : undir[u]){
        if(!vis[c])
            ret += go(c);
    }
    return ret;
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt" , "r" , stdin);
#endif
    ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        cin >> n >> m;
        init();
        for(int i = 0 ; i < m ; ++i){
            int u , v;
            cin >> u >> v;
            adj[u].pb(v);
        }

        run();

        ll ans = 0;
        for(int i = 1 ; i <= n ; ++i){
            for(int j : adj[i]){
                if(cmp[i] != cmp[j]){
                    indeg[cmp[j]]++;
                    outdeg[cmp[i]]++;
                    undir[cmp[i]].pb(cmp[j]);
                    undir[cmp[j]].pb(cmp[i]);
                }
            }
        }
        vector<pair<int , int> > res;
        memset(vis , false , sizeof vis);
        for(int i = 1 ; i <= n ; ++i){
            if(!vis[cmp[i]]){
                in = 0 , out = 0;
                cc++;
                if(go(cmp[i]) > 1)
                    res.pb({in , out});
            }
        }
        if(cc > 1)ans += cc;
        for(auto e : res){
            if(cc > 1)
                ans += max(1ll * (e.first - 1) * e.second , 1ll * e.first * (e.second - 1));
            else
                ans += 1ll * e.first * e.second;
        }
        cout << ans << "\n";
    }
}
