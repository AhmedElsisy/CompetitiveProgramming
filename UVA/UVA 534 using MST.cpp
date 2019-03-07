#include <bits/stdc++.h>
#define pb push_back
#define all(v) (v).begin() , (v).end()
#define popcnt(x) __builtin_popcount(x)
#define inf 0x3f3f3f3f
#define watch(x) cout << (#x) << " is " << (x) << endl
#define rand() (rand() << 15 | rand())

using namespace std;
typedef long long  ll;
const int N = 204;

int par[N] , sz[N];

void init(){
    iota(par , par + N , 0);
    memset(sz , 0 , sizeof sz);
}

int find_set(int u){
    return par[u] = (par[u] == u ? u : find_set(par[u]));
}

void union_set(int u , int v){
    u = find_set(u);
    v = find_set(v);

    if(u == v)
        return;

    if(sz[u] < sz[v])
        swap(u , v);

    par[v] = u;
    sz[u] += sz[v];
}

double dist(int x1 , int y1 , int x2 , int y2){
    int dx = x1 - x2 , dy = y1 - y2;
    return sqrt(dx * dx + dy * dy);
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt" , "r" , stdin);
#endif
    ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);
    int n , cs = 1;
    while(cin >> n && n){
        init();
        vector<pair<int , int> > v(n);
        for(auto &p : v)
            cin >> p.first >> p.second;

        vector<pair<double , pair<int , int> > > edge_list;
        for(int i = 0 ; i < n ; ++i){
            for(int j = i + 1 ; j < n ; ++j){
                edge_list.pb({dist(v[i].first , v[i].second , v[j].first , v[j].second) , {i , j}});
            }
        }


        sort(all(edge_list));
        double ans = 0.0;

        for(int i = 0 ; i < (int)edge_list.size() && find_set(0) != find_set(1) ; ++i){
            double cost = edge_list[i].first;
            int u = edge_list[i].second.first , v = edge_list[i].second.second;

            if(find_set(u) == find_set(v))
                continue;
            union_set(u , v);
            ans = max(ans , cost);
        }


        cout << "Scenario #" << cs++ << "\n";
        cout << "Frog Distance = " << fixed << setprecision(3) << ans << "\n\n";
    }
}
