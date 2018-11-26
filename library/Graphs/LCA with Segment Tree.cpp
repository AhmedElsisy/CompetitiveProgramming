const int N = 1e5 + 4;
int H[N] , F[N] , st[8 * N] , timer = 0;
vector<int> tour , adj[N];
void dfs(int node , int par , int dep){
    F[node] = (int)tour.size();
    tour.push_back(node);
    H[node] = dep;
    for(int child : adj[node]){
        if(child != par)dfs(child , node , dep + 1);
        tour.push_back(node);
    }
}

void build(int p , int l , int r){
    if(l == r){
        st[p] = tour[l];
    }
    else{
        int mid = (l + r) >> 1;
        build(p << 1 , l , mid);
        build((p << 1) + 1 , mid + 1 , r);
        int p1 = st[p << 1];
        int p2 = st[(p << 1) + 1];
        st[p] = (H[p1] < H[p2] ? p1 : p2);
    }
}

int query(int p , int l , int r , int i , int j){
    if(j < l || i > r)return -1;
    if(l >= i && r <= j)
        return st[p];
    int mid = (l + r) >> 1;
    int p1 = query(p << 1 , l , mid , i , j);
    int p2 = query((p << 1) + 1 , mid + 1 , r , i , j);
    if(p1 == -1)return p2;
    if(p2 == -1)return p1;
    return (H[p1] < H[p2] ? p1 : p2);
}

int LCA(int u , int v){
    int f = F[u] , s = F[v];
    if(f > s)swap(f , s);
    return query(1 , 0 , (int)tour.size() - 1 , f , s);
}


// dfs -> build -> query (call in order)
