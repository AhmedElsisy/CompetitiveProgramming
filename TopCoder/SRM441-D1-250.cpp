#include<bits/stdc++.h>
#define pb push_back
#define all(v) (v).begin() , (v).end()
#define popcnt(x) __builtin_popcount(x)
#define inf 0x3f3f3f3f
#define watch(x) cout << (#x) << " is " << (x) << endl
#define rand() (rand() << 15 | rand())
using namespace std;
typedef long long  ll;
const int N = 54;
vector<int> adj[N];
bool vis[N];

void dfs(int u){
    vis[u] = true;
    for(int c : adj[u]){
        if(!vis[c])
            dfs(c);
    }
}

class PerfectPermutation{
public:
    int reorder(vector <int> P){
        int n = (int)P.size();
        for(int i = 0 ; i < n ; ++i)
            adj[i].clear() , vis[i] = false;

        for(int i = 0 ; i < n ; ++i){
            adj[i].pb(P[i]);
        }

        int cnt = 0;
        for(int i = 0 ; i < n ; ++i){
            if(!vis[i]){
                ++cnt;
                dfs(i);
            }
        }

        return (cnt == 1 ? 0 : cnt);
    }
};
