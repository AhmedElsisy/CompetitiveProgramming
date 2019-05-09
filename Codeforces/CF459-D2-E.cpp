#include <bits/stdc++.h>
#define pb push_back
#define all(v) (v).begin() , (v).end()
#define popcnt(x) __builtin_popcount(x)
#define inf 0x3f3f3f3f
#define watch(x) cout << (#x) << " is " << (x) << endl
#define rand() (rand() << 15 | rand())
using namespace std;
typedef long long  ll;
struct Edge{
    int u , v , c;
    bool operator < (const Edge &other) const{
        return c < other.c;
    }
};
int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt" , "r" , stdin);
#endif
    ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);
    int n , m;
    cin >> n >> m;
    vector<Edge> edgeList;
    for(int i = 0 ; i < m ; ++i){
        int u , v , c;
        cin >> u >> v >> c;
        edgeList.pb({u , v , c});
    }
    sort(all(edgeList));
    vector<int> val(n + 1 , 0);

    for(int i = 0 ; i < m ; ++i){
        vector<pair<int , int> > maxi;
        int j = i;
        while(j < m && edgeList[j].c == edgeList[i].c){
            auto e = edgeList[j];
            maxi.emplace_back(e.v , val[e.u] + 1);
            ++j;
        }

        for(auto p : maxi)
            val[p.first] = max(val[p.first] , p.second);
        i = j - 1;
    }

    cout << *max_element(all(val)) << "\n";
}
