#include<bits/stdc++.h>
#define pb push_back
#define all(v) (v).begin() , (v).end()
#define popcnt(x) __builtin_popcount(x)
#define inf 0x3f3f3f3f
#define watch(x) cout << (#x) << " is " << (x) << endl
#define rand() (rand() << 15 | rand())
using namespace std;
typedef long long  ll;
const int N = 50 * 50 + 3;
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

bool is_lower(char c){
    return c >= 'a' && c <= 'z';
}

int getv(char c){
    if(isalpha(c)){
        return (islower(c) ? (c - 'a' + 10) : (c - 'A' + 36));
    }
    return c - '0';
}
int dx[] = {0 , 1};
int dy[] = {1 , 0};
class ActivateGame{
public:
    int findMaxScore(vector <string> grid){
        int n = (int)grid.size() , m = (int)grid[0].size();
        init();
        vector<pair<int , pair<int , int> > > edgeList;
        for(int i = 0 ; i < n ; ++i){
            for(int j = 0 ; j < m ; ++j){
                for(int k : {0 , 1}){
                    int x = i + dx[k] , y = j + dy[k];
                    if(x < n && y < m){
                        edgeList.pb({-abs(getv(grid[i][j]) - getv(grid[x][y])) , {i * m + j , x * m + y}});
                    }
                }
            }
        }

        int ret = 0;
        sort(all(edgeList));
        for(auto e : edgeList){
            int u = e.second.first , v = e.second.second , cost = -e.first;
            if(f(u) != f(v)){
                ret += cost;
                unite(u , v);
            }
        }
        return ret;
    }
};
