const int N = 1e5 + 4;
int dfs_num[N] , dfs_low[N] , cmp[N] , timer = 0 , n , m;
bool vis[N];
vector<int> adj[N] , adj2[N];
vector<pair<int , int> > Bridges;
stack<int> st;

// build bridge tree

void extract(int u){
    while(1){
        int v = st.top();st.pop();
        cmp[v] = u;
        if(u == v)break;
    }
}

void dfs(int u , int p = -1){
    dfs_num[u] = dfs_low[u] = timer++;
    vis[u] = true;
    st.push(u);
    for(int c : adj[u]){
        if(p == c)continue;
        if(!vis[c]){
            dfs(c , u);
            dfs_low[u] = min(dfs_low[u] , dfs_low[c]);
            if(dfs_low[c] > dfs_num[u]){
                extract(c);
                Bridges.emplace_back(u , c);
            }
        }
        else dfs_low[u] = min(dfs_low[u] , dfs_num[c]);
    }
    if(p == -1)
        extract(u);
}

void build(){       // you can use adj2[] as Bridge Tree
    for(int i = 0 ; i < (int)Bridges.size() ; ++i){
        int u = cmp[Bridges[i].first] , v = cmp[Bridges[i].second];
        adj2[u].pb(v);
        adj2[v].pb(u);
    }
}

void init(){
    for(int i = 0 ; i <= n ; ++i)
        adj[i].clear() , adj2[i].clear();
    memset(vis , false , sizeof vis);
    timer = 0;
    Bridges.clear();
}
