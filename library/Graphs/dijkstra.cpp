const int N = 2e5;

vector<pair<int , int> > adj[N];
int dis[N];

void pre(){
    memset(dis , inf , sizeof dis);
}

void Dijkstra(int s){
    priority_queue<pair<int , int> , vector<pair<int , int> > , greater<pair<int , int> > > pq;
    dis[s] = 0;
    pq.push({0 , s});

    while(!pq.empty()){
        auto top = pq.top();pq.pop();

        if(top.first > dis[top.second])continue;

        for(auto child : adj[top.second]){

            if(dis[child.first] > dis[top.second] + child.second){
                dis[child.first] = dis[top.second] + child.second;
                pq.push({dis[child.first] , child.first});
            }
        }
    }
}




