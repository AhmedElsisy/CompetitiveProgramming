/*
    first of all we want to minimize all edges cost to minimize its product.
    because of costs are powers of two so number of divisors is log2(cost) + 1
    and log2(a * b) = log2(a) + log2(b) so we change all costs to its log2 value to avoid overflow
    then run minimum spanning tree algorithm (kruskal or prim) to get summation of minimum edges
    total complexity : O(M log N)
*/
#include <bits/stdc++.h>
#define pb push_back
#define all(v) (v).begin() , (v).end()
#define popcnt(x) __builtin_popcount(x)
#define inf 0x3f3f3f3f
#define watch(x) cout << (#x) << " is " << (x) << endl
#define F first
#define S second

using namespace std;
typedef long long  ll;

const int N = 1e5 + 4;

int p[N] , sz[N];
vector<pair<pair<int , int> , int> > elist;

void init(){
    iota(p , p + N , 0);
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

int mst(){
    int ret = 0;
    sort(all(elist) , [](pair<pair<int , int> , int> a , pair<pair<int ,int> , int> b){
            return a.S < b.S;
    });
    for(int i = 0 ; i < (int)elist.size() ; ++i){
        int u = elist[i].F.F , v = elist[i].F.S , cost = elist[i].S;
        if(f(u) == f(v))continue;

        join(u , v);
        ret += cost;
    }
    return ret + 1;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r" , stdin);
#endif
    ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        init();
        int n , m;
        cin >> n >> m;
        int u , v;
        ll c;
        for(int i = 0 ; i < m ; ++i){
            cin >> u >> v >> c;
            int cost = log2(c);
            elist.pb({{u , v} , cost});
        }
        cout << mst() << "\n";
    }
    return 0;
}
