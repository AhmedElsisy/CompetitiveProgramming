const int N = 1e5 + 4;
int dfs_num[N] , dfs_low[N] , timer = 0 , n , m;
bool vis[N] , artPoints[N];
vector<int> adj[N];
// get articulation points in undirected graph
void dfs(int u , int p = -1){
    dfs_num[u] = dfs_low[u] = timer++;
    vis[u] = true;
    int cnt = 0;
    for(int c : adj[u]){
        if(p == c)continue;
        if(!vis[c]){
            dfs(c , u);
            ++cnt;
            dfs_low[u] = min(dfs_low[u] , dfs_low[c]);
            if(p != -1 && dfs_low[c] >= dfs_num[u])
                artPoints[u] = true;
        }
        else dfs_low[u] = min(dfs_low[u] , dfs_num[c]);
    }
    if(p == -1 && cnt > 1)
        artPoints[u] = true;
}

void init(){
    for(int i = 0 ; i < N ; ++i)
        adj[i].clear();
    memset(vis , false , sizeof vis);
    memset(artPoints , false , sizeof artPoints);
    timer = 0;
}
