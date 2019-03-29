const int N = 104;
struct Edge{
    int u , v , c;
};

vector<int> adj[N] , par , to;
vector<Edge> edgeList;
int n , m , src , snk;

void init(){            // to be called every TESTCASE
    for(int i = 0 ; i < N ; ++i)
        adj[i].clear();
    edgeList.clear();
}

void add_edge(int u , int v , int c){
    adj[u].push_back((int)edgeList.size());
    edgeList.push_back({u , v , c});
}

void add_biedge(int u , int v , int c){
    add_edge(u , v , c);
    add_edge(v , u , 0);
}

int vid = 1 , vis[N];
int dfs(int u , int mn){
    if(u == snk)
        return mn;
    vis[u] = vid;
    for(int child : adj[u]){
        int v = edgeList[child].v , c = edgeList[child].c;
        if(vis[v] == vid || !c)continue;
        int ret = dfs(v , min(mn , c));
        edgeList[child].c -= ret;
        edgeList[child ^ 1].c += ret;
        if(ret)return ret;          // found path return
    }
    return 0;
}

int FordFulkerson(){
    int mf = 0;
    while(1){
        vid++;
        int f = dfs(src , 1e9);
        if(!f)break;    // no flow
        mf += f;
    }
    return mf;
}

