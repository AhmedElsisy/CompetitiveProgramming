/**
    first we take the input & store banks in vector of pair
    function to convert cords into index
    build Vin & Vout
    build the graph src = 0 , snk = 2 * n * m + 2
    run Max flow
    check whether the max flow is equal to number of banks
**/

#include<bits/stdc++.h>
#define pb push_back
#define all(v) (v).begin() , (v).end()
#define popcnt(x) __builtin_popcount(x)
#define inf 0x3f3f3f3f
#define watch(x) cout << (#x) << " is " << (x) << endl
#define rand() (rand() << 15 | rand())
using namespace std;
typedef long long  ll;
int dx[] = {0 , 0 , 1 , -1 , 1 , 1 , -1 , -1};
int dy[] = {1 ,-1 , 0 , 0 , -1 , 1 ,  1 , -1};

const int N = 4 * 50 * 50 + 4;  // edit number of nodes here
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
int h , w , m , in[N] , out[N];
int get_indx(int i , int j){
    return ((i * w) + j) + 1;
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt" , "r" , stdin);
#endif
    ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        init();
        cin >> h >> w >> m;
        vector<pair<int , int> > banks(m);
        for(auto &e : banks){
            cin >> e.first >> e.second;
            e.first-- , e.second--;
        }
        src = 1;
        snk = 2 * h * w + 2;
        n = 2 * h * w + 2;

        for(int i = 0 ; i < h ; ++i){
            for(int j = 0 ; j < w ; ++j){
                int u = get_indx(i , j);
                in[u] = 2 * u , out[u] = 2 * u + 1;
            }
        }
        for(int i = 0 ; i < h ; ++i){
            for(int j = 0 ; j < w ; ++j){
                int u = get_indx(i , j);
                add_biedge(in[u] , out[u] , 1);
                for(int k = 0 ; k < 4 ; ++k){
                    int x = i + dx[k] , y = j + dy[k];
                    if(i >= 0 && i < h && j >= 0 && j < w){
                        int v = get_indx(x , y);
                        add_biedge(out[u] , in[v] , 1);
                    }
                }
            }
        }

        for(auto e : banks){
            int u = get_indx(e.first , e.second);
            add_biedge(src , in[u] , 1);
        }
        for(int i = 0 ; i < h ; ++i)
            add_biedge(out[get_indx(i , 0)] , snk , 1) , add_biedge(out[get_indx(i , w - 1)] , snk , 1);
        for(int i = 0 ; i < w ; ++i)
            add_biedge(out[get_indx(0 , i)] , snk , 1) , add_biedge(out[get_indx(h - 1 , i)] , snk , 1);

        int mf = EdmondKarp();
        cout << (mf == m ? "possible" : "not possible") << "\n";
    }
}
