const int N = 1e5 + 4;

int p[N] , sz[N];
vector<pair<pair<int , int> , int> > elist;

void init(){
    iota(p , p + N , 0); // 0 1 2 3
    memset(sz , 0 , sizeof sz);
    elist.clear();
}

int f(int u){
    return p[u] = (p[u] == u ? u : f(p[u]));
}

void join(int u , int v){
    u = f(u) , v = f(v);
    if(u == v)
        return;
    if(sz[u] > sz[v])
        swap(u , v);
    p[u] = v;
    sz[v] += sz[u];
}

// long long
int mst(){
    int ret = 0;
    sort(all(elist) , [](pair<pair<int , int> , int> a , pair<pair<int ,int> , int> b){
            return a.second < b.second;
    });
    for(int i = 0 ; i < (int)elist.size() ; ++i){
        int u = elist[i].first.first , v = elist[i].first.second , cost = elist[i].second;
        if(f(u) == f(v))continue;

        join(u , v);
        ret += cost;
    }
    return ret;
}
// init every testcase
