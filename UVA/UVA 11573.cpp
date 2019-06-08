#include <bits/stdc++.h>
#define pb push_back
#define all(v) (v).begin() , (v).end()
#define popcnt(x) __builtin_popcount(x)
#define inf 0x3f3f3f3f
#define watch(x) cout << (#x) << " is " << (x) << endl
#define rand() (rand() << 15 | rand())
using namespace std;
typedef long long  ll;

int dx[] = {0 , 0 , 1 , -1 , 1 , 1 , -1 , -1};
int dy[] = {1 ,-1 , 0 , 0 , -1 , 1 ,  1 , -1};
int n , m;
vector<vector<bool> > vis;

bool valid(int i , int j){
    if(i < 0 || i >= n || j < 0 || j >= m || vis[i][j])
        return false;
    return true;
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt" , "r" , stdin); // remember to delete
#endif
//    ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);
    map<char , int> mp;
    mp['0'] = 3;
    mp['1'] = 6;
    mp['2'] = 0;
    mp['3'] = 5;
    mp['4'] = 2;
    mp['5'] = 4;
    mp['6'] = 1;
    mp['7'] = 7;
    cin >> n >> m;
    vector<vector<char> > v(n , vector<char>(m));
    for(int i = 0 ; i < n ; ++i){
        for(int j = 0 ; j < m ; ++j)
            cin >> v[i][j];
    }
    int q;
    cin >> q;
    while(q--){
        vector<vector<int> > dist(n , vector<int>(m , inf));
        vis.assign(n , vector<bool>(m , false));
        pair<int , int> sr , ds;
        cin >> sr.first >> sr.second >> ds.first >> ds.second;
        --sr.first , --sr.second , --ds.first , --ds.second;

        deque<pair<int , int> > q;
        dist[sr.first][sr.second] = 0;
        q.push_front(sr);
        while(!q.empty()){
            pair<int , int> top = q.front();
            q.pop_front();
            if(vis[top.first][top.second])
                continue;
            vis[top.first][top.second] = true;
            if(top == ds)
                break;

            int i = mp[v[top.first][top.second]];
            int x = top.first + dx[i] , y = top.second + dy[i];
            if(valid(x , y) && dist[top.first][top.second] < dist[x][y])
                q.push_front({x , y}) , dist[x][y] = dist[top.first][top.second];

            for(i = 0 ; i < 8 ; ++i){
                x = top.first + dx[i] , y = top.second + dy[i];
                if(valid(x , y) && dist[top.first][top.second] + 1 < dist[x][y])
                    q.push_back({x , y}) , dist[x][y] = dist[top.first][top.second] + 1;
            }
        }

        cout << dist[ds.first][ds.second] << "\n";
    }
}
