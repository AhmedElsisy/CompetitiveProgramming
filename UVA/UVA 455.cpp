#include <bits/stdc++.h>
#define pb push_back
#define all(v) (v).begin() , (v).end()
#define popcnt(x) __builtin_popcount(x)
#define inf 0x3f3f3f3f
#define watch(x) cout << (#x) << " is " << (x) << endl
#define rand() (rand() << 15 | rand())
using namespace std;
typedef long long  ll;


vector<int> buildZ(string &s){
    int n = (int)s.size();
    vector<int> Z(n , 0);
    int l = 0 , r = 0;
    for(int i = 1 ; i < n ; ++i){
        Z[i] = max(0 , min(Z[i - l] , r - i + 1));
        while(i + Z[i] < n && s[i + Z[i]] == s[Z[i]])
            l = i , r = i + Z[i] , ++Z[i];
    }
    return Z;
}



int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt" , "r" , stdin);
#endif
    ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;

        int n = (int)s.size();

        vector<int> d;
        for(int i = 1 ; i * i <= n ; ++i){
            if(n % i == 0){
                d.pb(i);
                if(i != n / i)d.pb(n / i);
            }
        }

        int res = -1;
        vector<int> Z = buildZ(s);
        sort(all(d));
        for(int x : d){
            bool ok = true;
            for(int i = x ; i < n ; i += x){
                ok &= (Z[i] >= x);
            }
            if(ok){
                res = x;
                break;
            }
        }

        cout << res << endl;
        if(t)cout << endl;
    }
}
