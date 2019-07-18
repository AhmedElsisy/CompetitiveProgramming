#include<bits/stdc++.h>
#define pb push_back
#define all(v) (v).begin() , (v).end()
#define popcnt(x) __builtin_popcount(x)
#define inf 0x3f3f3f3f
#define watch(x) cout << (#x) << " is " << (x) << endl
#define rand() (rand() << 15 | rand())
using namespace std;
typedef long long  ll;
const int N = 15 + 1;
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

int lcm(int a , int b){
    return a * (b / __gcd(a , b));
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt" , "r" , stdin);
#endif
    ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);
    int n , m;
    while(cin >> n >> m){
        if(!n && !m)
            return 0;
        vector<int> w(n + 1);
        for(int i = 1 ; i <= n ; ++i)
            cin >> w[i];

        vector<vector<int> > mat(n + 1 , vector<int>(n + 1));
        for(int i = 1 ; i <= n ; ++i){
            for(int j = 1 ; j <= n ; ++j){
                cin >> mat[i][j];
            }
        }

        int up = -1 , down = -1;
        vector<int> res;
        for(int msk = 1 ; msk < (1 << n) ; ++msk){
            if(popcnt(msk) != m)continue;
            vector<int> G;
            int nodes_sum = 0;
            for(int j = 0 ; j < n ; ++j){
                if(msk & (1 << j)){
                    G.pb(j + 1);
                    nodes_sum += w[j + 1];
                }
            }

            vector<pair<int , pair<int , int> > > edgeList;
            for(int i = 0 ; i < (int)G.size() ; ++i){
                for(int j = i + 1 ; j < (int)G.size() ; ++j){
                    edgeList.pb({mat[G[i]][G[j]] , {G[i] , G[j]}});
                }
            }

            init();
            int sum = 0;
            sort(all(edgeList));
            for(auto e : edgeList){
                if(f(e.second.first) == f(e.second.second))continue;
                sum += e.first;
                unite(e.second.first , e.second.second);
            }

            if(up == -1 && down == -1)
                up = sum , down = nodes_sum , res = G;

            int past = up * (lcm(down , nodes_sum) / down);
            int now = sum * (lcm(down , nodes_sum) / nodes_sum);
            if(now < past){
                up = sum , down = nodes_sum , res = G;
            }
            else if(now == past){
                if(G < res){
                    res = G;
                }
            }
        }
        cout << res[0];
        for(int i = 1 ; i < (int)res.size() ; ++i)
            cout << ' ' << res[i];
        cout << "\n";
    }
}
