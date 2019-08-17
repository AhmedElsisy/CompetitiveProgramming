const int N = 2e5 + 4;
int dfs_num[N] , dfs_low[N] , timer = 0 , n , m , cmp[N];
bool inStack[N] , vis[N];
stack<int> st;
vector<int> adj[N];
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
            cmp[t] = comp.size() - 1;
            comp.back().push_back(t);
            if(t == u)break;
        }
    }
}

void init(){
    for(int i = 0 ; i <= n ; ++i)
        adj[i].clear();
    memset(vis , false , sizeof vis);
    timer = 0;
    comp.clear();
}

void run(){                             // edit indexes of nodes (1 - based here)
    for(int i = 1 ; i <= n ; ++i){       // iterate over node to call SCC in every un-visted node
        if(!vis[i]){
            SCC(i);
        }
    }
}
