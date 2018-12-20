
const int N = 2e4 + 4 , LG = log2(1e4) + 4;

vector<int> adj[N];
int dp[N][LG] , st[N] , en[N] , timer = 0 , jump , n;

void dfs(int node , int par){
    st[node] = timer++;
    dp[node][0] = par;
    for(int i = 1 ; i < jump ; ++i){
        dp[node][i] = dp[dp[node][i - 1]][i - 1];
    }

    for(int child : adj[node]){
        if(child != par){
            dfs(child , node);
        }
    }
    en[node] = timer++;
}

bool is_ancestor(int u , int v){
    return st[u] <= st[v] && en[u] >= st[v];    // in case of u == v
}

int LCA(int u , int v){
    if(is_ancestor(u , v))return u;
    if(is_ancestor(v , u))return v;

    int up = jump;
    while(up >= 0){
        if(!is_ancestor(dp[u][up] , v))
            u = dp[u][up];
        --up;
    }

    return dp[u][0];
}

void pre(){
    jump = ceil(log2(n));
    int root = 1;
    dfs(root , root);
}


