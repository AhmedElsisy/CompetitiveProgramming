const int N = 2e5 + 4 , LG = log2(N) + 4;

vector<int> adj[N];
int dp[N][LG] , st[N] , en[N] , H[N] , timer = 0 , jump , n;

void dfs(int node , int par , int d){
    st[node] = timer++;
    dp[node][0] = par;
    for(int i = 1 ; i <= jump ; ++i){
        dp[node][i] = dp[dp[node][i - 1]][i - 1];
    }

    H[node] = d;

    for(int child : adj[node]){
        if(child != par){
            dfs(child , node , d + 1); // if weighted d + cost(node , child)
        }
    }
    en[node] = timer++;
}

bool is_ancestor(int u , int v){
    return st[u] <= st[v] && en[u] >= st[v];    // in case of u == v
}

int LCA(int u , int v){        // get LCA between two nodes in tree in O(log2(n))
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


int dist(int u , int v){        // get distance between two nodes in tree in O(log2(n))
    int ancestor = LCA(u , v);
    // if weighted H[node] should store total cost from root to node
    return (H[u] - H[ancestor]) + (H[v] - H[ancestor]);
}

int getKthParent(int u , int k){        // get Kth parent to node in tree (binary lifting)
    int pos = u;

    if(!k)
        return u;

    int l = jump; // max jump = log2(n)
    while(l >= 0){
        if(H[dp[u][l]] - H[pos] < k)
            u = dp[u][l];
        --l;
    }

    return dp[u][0];
}

int getCenter(int u , int v){       // get center of tree given two endpoints of the tree diameter
    int d = dist(u , v);

    if(d & 1){
        int c1 = -1 , c2 = -1;  // two centers in case of diameter length is odd
        if(H[u] > H[v]){
            c1 = getKthParent(u , d / 2));
            c2 = getKthParent(u , d / 2 + 1);
        }
        else{
            c1 = getKthParent(v , d / 2);
            c2 = getKthParent(v , d / 2 + 1);
        }
        return (c1 < c2 ? c1 : c2);      // returns minimal index
    }
    else{
        if(H[u] > H[v]){
            return getKthParent(u , d / 2);
        }
        else{
            return getKthParent(v , d / 2);
        }
    }
}

void pre(){
    jump = ceil(log2(n));
    int root = 1;
    dfs(root , root , 0);
}

