/*
    let cost[i][j] be the cost will pay for using this road in two directions
    so if cost[i][j] exceeds value f then greedily we buy a ticket for this road
    but we can buy at most k tickets then we choose greater values of (max(0 , cost[i][j] - f))
    the greater value of this expression the more we save money
*/

#include <bits/stdc++.h>
#define pb push_back
#define all(v) (v).begin() , (v).end()
#define popcnt(x) __builtin_popcount(x)
#define inf 0x3f3f3f3f
#define watch(x) cout << (#x) << " is " << (x) << endl

using namespace std;
typedef long long  ll;
const int N = 605;

int cost[N][N];

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r" , stdin);
#endif
    ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);
    int n , a , b , k , f;
    cin >> n >> a >> b >> k >> f;

    map<string , int> mapping;
    int indx = 0;

    vector<pair<int , int> > v(n);
    for(int i = 0 ; i < n ; ++i){
        string from , to;
        cin >> from >> to;

        if(!mapping.count(from))mapping[from] = indx++;
        if(!mapping.count(to))mapping[to] = indx++;

        v[i].first = mapping[from] , v[i].second = mapping[to];
    }

    int lst = -1 , ans = 0;
    for(int i = 0 ; i < n ; ++i){
        int mn = min(v[i].first , v[i].second) , mx = max(v[i].first , v[i].second);
        if(lst == -1){
            ans += a;
            cost[mn][mx] += a;
        }
        else{
            if(v[i].first == lst)ans += b , cost[mn][mx] += b;
            else ans += a , cost[mn][mx] += a;
        }
        lst = v[i].second;
    }


    vector<int> extra;
    for(int i = 0 ; i < 2 * n ; ++i){
        for(int j = 0 ; j < 2 * n ; ++j){
            if(cost[i][j] > f){
                extra.pb(cost[i][j] - f);
            }
        }
    }

    sort(all(extra) , greater<int>());

    for(int i = 0 ; i < min(k , (int)extra.size()) ; ++i){
        ans -= extra[i];
    }

    cout << ans << '\n';
}
