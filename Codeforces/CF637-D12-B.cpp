/*
   make a customized stack<string> from a set<int , string>
*/

#include <bits/stdc++.h>
#define pb push_back
#define all(v) (v).begin() , (v).end()
#define popcnt(x) __builtin_popcount(x)
#define inf 0x3f3f3f3f
#define watch(x) cout << (#x) << " is " << (x) << endl
#define F first
#define S second

using namespace std;
typedef long long  ll;

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r" , stdin);
#endif
    ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);
    int n;
    cin >> n;

    set<pair<int , string> > s;
    map<string , int> mp;

    int cnt = 2e5;
    for(int i = 0 ; i < n ; ++i){
        string str;
        cin >> str;
        if(!mp.count(str)){
            mp[str] = cnt--;
            s.insert({mp[str] , str});
        }
        else{
            auto it = s.find({mp[str] , str});
            s.erase(it);
            mp[str] = cnt--;
            s.insert({mp[str] , str});
        }
    }

    for(auto x : s)
        cout << x.S << '\n';
}
