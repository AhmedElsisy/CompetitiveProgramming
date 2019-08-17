#include<bits/stdc++.h>
#define pb push_back
#define all(v) (v).begin() , (v).end()
#define popcnt(x) __builtin_popcount(x)
#define inf 0x3f3f3f3f
#define watch(x) cout << (#x) << " is " << (x) << endl
#define rand() (rand() << 15 | rand())
using namespace std;
typedef long long  ll;
const int N = 50 + 1;
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

class KingdomReorganizatio{
public:
    int getCost(vector <string> kingdom, vector <string> build, vector <string> destroy){
        int n = (int)kingdom.size();
        int m = (int)kingdom[0].size();
        init();
        vector<pair<int , pair<int , int> > > B , D;
        for(int i = 0 ; i < n ; ++i){
            for(int j = i + 1 ; j < m ; ++j){
                if(kingdom[i][j] == '1' && kingdom[j][i] == '1'){
                    D.push_back({-(is_lower(destroy[i][j]) ? destroy[i][j] - 'a' + 26 : destroy[i][j] - 'A') , {i , j}});
                }
                else{
                    B.push_back({(is_lower(build[i][j]) ? build[i][j] - 'a' + 26 : build[i][j] - 'A') , {i , j}});
                }
            }
        }

        int ret = 0;
        sort(all(D));
        for(auto e : D){
            int u = e.second.first , v = e.second.second , cost = -e.first;
            if(f(u) == f(v)){
                ret += cost;
            }
            else unite(u , v);
        }

        sort(all(B));
        for(auto e : B){
            int u = e.second.first , v = e.second.second , cost = e.first;
            if(f(u) != f(v)){
                ret += cost;
                unite(u , v);
            }
        }

        return ret;
    }
};
