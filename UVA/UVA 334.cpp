#include <bits/stdc++.h>
#define pb push_back
#define all(v) (v).begin() , (v).end()
#define popcnt(x) __builtin_popcount(x)
#define inf 0x3f3f3f3f
#define watch(x) cout << (#x) << " is " << (x) << endl
#define rand() (rand() << 15 | rand())

using namespace std;
typedef long long  ll;
const int N = 402;

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt" , "r" , stdin);
#endif
    ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);
    int n , cs = 1;
    while(cin >> n && n){
        vector<vector<int> > adjMat(N , vector<int>(N , 0));
        map<string , int> mapping;
        map<int , string> to_str;
        int curID = 0;
        for(int i = 0 ; i < n ; ++i){
            int m;
            cin >> m;
            vector<string> v(m);
            for(int j = 0 ; j < m ; ++j){
                cin >> v[j];
                int indx = -1;
                if(mapping.count(v[j]))indx = mapping[v[j]];
                else indx = mapping[v[j]] = curID++ , to_str[indx] = v[j];

                if(j){
                    int prev_indx = mapping[v[j - 1]];
                    adjMat[prev_indx][indx] = 1;
                }
            }
        }

        int m;
        cin >> m;
        while(m--){
            string s , t;
            cin >> s >> t;
            int i = mapping[s] , j = mapping[t];
            adjMat[i][j] = 1;
        }

        for(int k = 0 ; k < curID ; ++k){
            for(int i = 0 ; i < curID ; ++i){
                for(int j = 0 ; j < curID ; ++j){
                    adjMat[i][j] |= (adjMat[i][k] && adjMat[k][j]);
                }
            }
        }

        set<pair<int , int> > s;
        for(int i = 0 ; i < curID ; ++i){
            for(int j = i + 1 ; j < curID ; ++j){
                if(!adjMat[i][j] && !adjMat[j][i]){
                    s.insert({i , j});
                }
            }
        }
        if(s.empty()){
            printf("Case %d, no concurrent events.\n" , cs++);
            continue;
        }

        printf("Case %d, %d concurrent events:\n" , cs++ , (int)s.size());
        int cnt = 2;
        for(auto p : s){
            if(!cnt--)break;
            printf("(%s,%s) " , to_str[p.first].c_str() , to_str[p.second].c_str());
        }
        printf("\n");
    }
}
