#include<bits/stdc++.h>
#define pb push_back
#define all(v) (v).begin() , (v).end()
#define popcnt(x) __builtin_popcount(x)
#define inf 0x3f3f3f3f
#define watch(x) cout << (#x) << " is " << (x) << endl
#define rand() (rand() << 15 | rand())
using namespace std;
typedef long long  ll;
const int N = 204;  // edit number of nodes here
struct Edge{
    int u , v , c;
};

vector<int> adj[N] , par , to;
vector<Edge> edgeList;
int sz , src , snk;

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
        par.assign(sz + 1 , -1);
        to.assign(sz + 1 , -1);
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
int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt" , "r" , stdin);
#endif
    int t , cs = 1;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        init();
        vector<int> a(n);
        src = 0;
        for(int i = 0 ; i < n ; ++i){
            cin >> a[i];
            add_biedge(src , i + 1 , 1);
        }

        int m;
        cin >> m;
        vector<int> b(m);
        snk = n + m + 1;
        sz = snk + 1;
        for(int i = 0 ; i < m ; ++i){
            cin >> b[i];
            add_biedge(n + i + 1 , snk , 1);
        }

        for(int i = 0 ; i < n ; ++i){
            for(int j = 0 ; j < m ; ++j){
                if((a[i] == 0 && b[j] == 0) || (a[i] && b[j] % a[i] == 0))
                    add_biedge(i + 1 , n + j + 1 , 1);
            }
        }

        printf("Case %d: %d\n" , cs++ , EdmondKarp());
    }
}
