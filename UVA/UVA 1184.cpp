#include<bits/stdc++.h>
#define pb push_back
#define all(v) (v).begin() , (v).end()
#define popcnt(x) __builtin_popcount(x)
#define inf 0x3f3f3f3f
#define watch(x) cout << (#x) << " is " << (x) << endl
#define rand() (rand() << 15 | rand())
using namespace std;
typedef long long  ll;
const int N = 124;  // edit number of nodes here
struct Edge{
    int u , v , c;
};

vector<int> adj[N] , par , to;
vector<Edge> edgeList;
int max_node , src , snk;

void init(){        // FOR EVERY TESTCASE you should call init()
    for(int i = 0 ; i <= max_node ; ++i)
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

int augment(int u , int mn){
    if(par[u] == -1){
        return (u == src ? mn : 0);
    }
    int ret = augment(par[u] , min(mn , edgeList[to[u]].c));
    edgeList[to[u]].c -= ret;
    edgeList[to[u] ^ 1].c += ret;
    return ret;
}

int EdmondKarp(){
    int mf = 0;
    while(1){
        par.assign(max_node + 1 , -1);
        to.assign(max_node + 1 , -1);
        queue<int> q;
        q.push(src);
        while(!q.empty()){
            int top = q.front();
            q.pop();
            if(top == snk)break;
            for(int child : adj[top]){
                int u = top , v = edgeList[child].v , c = edgeList[child].c;
                if(par[v] != -1 || !c || v == src)continue;
                par[v] = u;
                to[v] = child;      // indx of the edge in edgeList
                q.push(v);
            }
        }
        int f = augment(snk , 1e9);
        if(!f)break;      // means no path
        mf += f;
    }
    return mf;
}

// you need to initialize three variable -> (src , snk , n)

int in[N] , out[N];

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt" , "r" , stdin);
#endif
    ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n , m;
        cin >> n >> m;
        src = 1;
        snk = 2 * n + 2;
        max_node = snk + 1;
        init();
        for(int i = 1 ; i <= n ; ++i){
            in[i] = 2 * i;
            out[i] = 2 * i + 1;
        }
        for(int i = 0 ; i < m ; ++i){
            int u , v;
            cin >> u >> v;
            add_biedge(in[u] , out[v] , 1);
        }
        for(int i = 1 ; i <= n ; ++i)
            add_biedge(src , in[i] , 1) , add_biedge(out[i] , snk , 1);

        cout << n - EdmondKarp() << "\n";
    }
}
