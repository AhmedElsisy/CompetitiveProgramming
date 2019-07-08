const int N = 1e5 + 4;
int dfs_num[N] , dfs_low[N] , timer = 0 , n , m;
bool vis[N];
vector<int> adj[N];
vector<pair<int , int> > Bridges;
// get Bridges in undirected graph
void dfs(int u , int p){
    dfs_num[u] = dfs_low[u] = timer++;
    vis[u] = true;
    for(int c : adj[u]){
        if(p == c)continue;
        if(!vis[c]){
            dfs(c , u);
            dfs_low[u] = min(dfs_low[u] , dfs_low[c]);
            if(dfs_low[c] > dfs_num[u]){
                Bridges.emplace_back(u , c);
            }
        }
        else dfs_low[u] = min(dfs_low[u] , dfs_num[c]);
    }
}

void init(){
    for(int i = 0 ; i <= n ; ++i)
        adj[i].clear();
    memset(vis , false , sizeof vis);
    timer = 0;
    Bridges.clear();
}
