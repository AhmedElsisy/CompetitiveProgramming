#include <bits/stdc++.h>
#define pb push_back
#define all(v) (v).begin() , (v).end()
#define popcnt(x) __builtin_popcount(x)
#define inf 0x3f3f3f3f
#define watch(x) cout << (#x) << " is " << (x) << endl
#define rand() (rand() << 15 | rand())

using namespace std;
typedef long long  ll;

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

        vector<pair<int , int> > v(n);
        vector<vector<double> > adjMat(n , vector<double>(n , 0.0));
        for(auto &p : v)
            cin >> p.first >> p.second;

        for(int i = 0 ; i < n ; ++i){
            for(int j = 0 ; j < n ; ++j){
                adjMat[i][j] = dist(v[i].first , v[i].second , v[j].first , v[j].second);
            }
        }

        for(int k = 0 ; k < n ; ++k){
            for(int i = 0 ; i < n ; ++i){
                for(int j = 0 ; j < n ; ++j){
                    adjMat[i][j] = min(adjMat[i][j] , max(adjMat[i][k] , adjMat[k][j]));
                }
            }
        }
        cout << "Scenario #" << cs++ << "\n";
        cout << "Frog Distance = " << fixed << setprecision(3) << adjMat[0][1] << "\n\n";
    }
}
