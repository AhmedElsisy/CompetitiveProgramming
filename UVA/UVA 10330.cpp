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
const int N = 200 + 5;
struct Edge{
    int u , v , c;
};

vector<int> adj[N] , par , to;
vector<Edge> edgeList;
int n , src , snk;

void init(){        // FOR EVERY TESTCASE you should call init()
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

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt" , "r" , stdin);
#endif
    int reg;
    while(cin >> reg){
        init();
        vector<int> cap(reg + 1) , in(reg + 1) , out(reg + 1);
        for(int i = 1 ; i <= reg ; ++i)
            cin >> cap[i];

        for(int i = 1 ; i <= reg ; ++i){
            in[i] = 2 * i - 1;
            out[i] = 2 * i;
            add_biedge(in[i] , out[i] , cap[i]);
        }

        n = 2 * reg + 2;
        src = 0 , snk = 2 * reg + 1;

        int m;
        cin >> m;
        for(int i = 0 ; i < m ; ++i){
            int u , v , c;
            cin >> u >> v >> c;
            add_biedge(out[u] , in[v] , c);
        }

        int B , D;
        cin >> B >> D;
        for(int i = 0 ; i < B ; ++i){
            int x;
            cin >> x;
            add_biedge(src , in[x] , inf);
        }

        for(int i = 0 ; i < D ; ++i){
            int x;
            cin >> x;
            add_biedge(out[x] , snk , inf);
        }

        cout << EdmondKarp() << "\n";
    }
}
