const int N = 1e5 + 1;
int sz[N] , p[N];

void init(){
    iota(p , p + N , 0); // 0 1 2 3 .. N
    fill(sz , sz + N , 1);
}

int f(int u){
    return p[u] = (p[u] == u ? u : f(p[u]));
}

void unite(int u , int v){
    u = f(u);
    v = f(v);

    if(u == v)return;

    if(sz[v] < sz[u])swap(u , v);

    p[u] = v;
    sz[v] += sz[u];
}
