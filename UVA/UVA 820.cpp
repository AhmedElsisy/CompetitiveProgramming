#include <bits/stdc++.h>
#define pb push_back
#define all(v) (v).begin() , (v).end()
#define popcnt(x) __builtin_popcount(x)
#define inf 0x3f3f3f3f
#define watch(x) cout << (#x) << " is " << (x) << endl
#define rand() (rand() << 15 | rand())

using namespace std;
typedef long long  ll;
typedef long double  ld;

const int N = 104;
struct Edge{
    int u , v , c;
};

vector<int> adj[N] , par , to;
vector<Edge> edgeList;
int n , m , src , snk;

void init(){
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
        par.assign(n + 1 , -1);
        to.assign(n + 1 , -1);
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
                to[v] = child;
                q.push(v);
            }
        }
        int f = augment(snk , 1e9);
        if(!f)break;      // means no path
        mf += f;
    }
    return mf;
}
int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt" , "r" , stdin);
#endif
    ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);
    int cs = 1;
    while(cin >> n && n){
        init();
        cin >> src >> snk >> m;
        for(int i = 0 ; i < m ; ++i){
            int u , v , c;
            cin >> u >> v >> c;
            add_biedge(u , v , c);
            add_biedge(v , u , c);
        }
        cout << "Network " << cs++ << "\n";
        cout << "The bandwidth is " << EdmondKarp() << ".\n\n";
    }
}
