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

const int N = 20010;

bool vis[N];
vector<pair<int,int> > adj[N];
int dis[N];


void dijkstra(int s){
    multiset<pair<int,int> > pq;
    dis[s] = 0;
    pq.insert(mp(0,s));
    while(!pq.empty()){
        pair<int,int> x = *pq.begin();
        pq.erase(pq.begin());
        int nn = x.second , ww = x.first;
        if(vis[nn])continue;
        vis[nn] = true;
        for(int i=0;i<adj[nn].size();++i){
            int n = adj[nn][i].first , w = adj[nn][i].second;
            if(dis[nn] + w < dis[n]){
                dis[n] = dis[nn] + w;
                pq.insert(mp(dis[n],n));
            }
        }
    }
}

void intialize(){
    for(int i=0;i<N;++i)
        adj[i].clear();
}

int main() {
    int T;
    int cn = 1;
    scanf("%d",&T);
    while(T--){
        for(int i=0;i<N;++i)dis[i] = inf;
        memset(vis,false,sizeof vis);
        intialize();
        int n,m,s,t;
        scanf("%d %d %d %d",&n,&m,&s,&t);
        for(int i=0;i<m;++i){
            int x,y,w;
            scanf("%d %d %d",&x,&y,&w);
            adj[x].pb(mp(y,w));
            adj[y].pb(mp(x,w));
        }
        dijkstra(s);
        if(!vis[t]){
            printf("Case #%d: unreachable\n",cn++);
        }
        else {
            printf("Case #%d: %d\n",cn++,dis[t]);
        }
    }


    return 0;
}
