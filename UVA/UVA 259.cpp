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
    while(1){
        init();
        vector<string> lines;
        string line;
        while(getline(cin , line)){
            if(line.empty()){
                break;
            }
            lines.push_back(line);
        }

        if(lines.empty())break;

        int sum = 0;
        n = 27 + 10 + 1;
        src = 0;
        snk = 27 + 10;
        vector<int> a(27);
        for(string x : lines){
            int from = x[0] - 'A' + 1;
            a[from] = x[1] - '0';
            sum += a[from];
            add_biedge(src , from , a[from]);
            for(int i = 3 ; i + 1 < (int)x.size() ; ++i){
                int to = 27 + (x[i] - '0');
                add_biedge(from , to , 1);
            }
        }

        for(int i = 27 ; i < 27 + 10 ; ++i)
            add_biedge(i , snk , 1);

        int mf = EdmondKarp();
        if(mf != sum)
            cout << "!\n";
        else{
            vector<int> res(10 , -1);
            for(int i = 0 ; i < (int)edgeList.size() ; ++i){
                if(i & 1)continue;
                if(edgeList[i].u == src || edgeList[i].v == snk)continue;
                if(edgeList[i].c == 0){
                    res[edgeList[i].v - 27] = edgeList[i].u;
                }
            }

            for(int i = 0 ; i < 10 ; ++i)
                cout << (res[i] == -1 ? '_' : (char)('A' + res[i] - 1));
            cout << "\n";
        }
    }
}
