#include <bits/stdc++.h>
#define pb push_back
#define inf 0x3f3f3f3f
#define all(v) (v).begin() , (v).end()
#define mp make_pair

using namespace std;

typedef vector<int> vi;
typedef long long   ll;

int dx[] = {0 , 0 , 1 , -1 , 1 , 1 , -1 , -1};
int dy[] = {1 ,-1 , 0 , 0 , -1 , 1 ,  1 , -1};

const int N = 1010;

int grid[N][N];
bool vis[N][N];
int dis[N][N];
int n , m;

void dijkstra(int x,int y){
    multiset<pair<int,pair<int,int> > > pq;
    dis[x][y] = grid[x][y];
    pq.insert(mp(grid[x][y],mp(x,y)));
    while(!pq.empty()){
        pair<int,pair<int,int> > node = *pq.begin();
        pq.erase(pq.begin());
        pair<int,int> rp = node.second;
        if(vis[rp.first][rp.second])continue;       // 0 1 2 3 4 5
        vis[rp.first][rp.second] = true;
        for(int i=0;i<4;++i){
            pair<int,int> nei = mp(rp.first + dx[i] , rp.second + dy[i]);
            int w = grid[nei.first][nei.second];
            if(nei.first >= n || nei.first < 0 || nei.second >= m || nei.second < 0)
                continue;
            if(dis[rp.first][rp.second] + w < dis[nei.first][nei.second]){
                dis[nei.first][nei.second] = dis[rp.first][rp.second] + w;
                pq.insert(mp(dis[nei.first][nei.second],mp(nei.first,nei.second)));
            }
        }
    }
}

void intialize(){
    for(int i=0;i<N;++i){
        for(int j=0;j<N;++j){
            dis[i][j] = inf;
        }
    }
}

int main() {
    int T;
    scanf("%d",&T);
    while(T--){
        memset(vis,0,sizeof vis);
        intialize();
        scanf("%d %d",&n,&m);
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                cin>>grid[i][j];
            }
        }
        dijkstra(0,0);
        printf("%d\n",dis[n-1][m-1]);
    }
    return 0;
}
