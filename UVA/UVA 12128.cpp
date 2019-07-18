/*
    let's binary search the minimum separation trying to make it maximum possible
    then we get the minimum separation so BFS using this information to get the shortest path
    before binary search we need given separation i decide in bs i want to know whether it valid or not(i can reach my destination)
    so let's call bfs multiple sources to know for each cell what the minimum distance between this cell and other enemy bases
*/

#include <bits/stdc++.h>
#define pb push_back
#define all(v) (v).begin() , (v).end()
#define popcnt(x) __builtin_popcount(x)
#define inf 0x3f3f3f3f
#define watch(x) cout << (#x) << " is " << (x) << endl
#define rand() (rand() << 15 | rand())
using namespace std;
typedef long long  ll;

struct cell{
    int x , y;
};

int dx[] = {0 , 0 , 1 , -1 , 1 , 1 , -1 , -1};
int dy[] = {1 ,-1 , 0 , 0 , -1 , 1 ,  1 , -1};
const int N = 1e3 + 4;
int dist[N][N] , grid[N][N];
cell st , en;
int k , n , m;

bool isgoodMove(int x , int y){
    if(x >= n || x < 0 || y >= m || y < 0)
        return false;
    return true;
}

bool valid(int mid){
    memset(dist , inf , sizeof dist);
    queue<cell> q;
    if(grid[st.x][st.y] < mid)return false;
    dist[st.x][st.y] = 0;
    q.push(st);
    while(!q.empty()){
        cell top = q.front();q.pop();
        if(top.x == en.x && top.y == en.y)break;

        for(int i = 0 ; i < 4 ; ++i){
            cell to = {top.x + dx[i] , top.y + dy[i]};
            if(!isgoodMove(to.x , to.y) || grid[to.x][to.y] < mid)continue;
            if(dist[to.x][to.y] == inf){
                q.push(to);
                dist[to.x][to.y] = dist[top.x][top.y] + 1;
            }
        }
    }
    return dist[en.x][en.y] != inf;
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt" , "r" , stdin);
#endif
    ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        cin >> k >> n >> m;
        cin >> st.x >> st.y >> en.x >> en.y;
        vector<cell> bases(k);
        for(auto &e : bases)
            cin >> e.x >> e.y;

        memset(grid , inf , sizeof grid);
        queue<cell> q;
        for(auto e : bases)
            q.push(e) , grid[e.x][e.y] = 0;

        while(!q.empty()){
            cell top = q.front();q.pop();
            for(int i = 0 ; i < 4 ; ++i){
                cell to = {top.x + dx[i] , top.y + dy[i]};
                if(!isgoodMove(to.x , to.y))continue;
                if(grid[to.x][to.y] == inf){
                    q.push(to);
                    grid[to.x][to.y] = grid[top.x][top.y] + 1;
                }
            }
        }
        int l = 0 , r = n + m - 2 , ans = -1;
        while(l <= r){
            int mid = (l + r) >> 1;
            if(valid(mid)){
                l = l + 1;
                ans = mid;
            }
            else{
                r = mid - 1;
            }
        }
        valid(ans);
        cout << ans << ' ' << dist[en.x][en.y] << "\n";
    }
}
