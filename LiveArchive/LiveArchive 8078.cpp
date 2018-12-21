#include <bits/stdc++.h>
#define pb push_back
#define all(v) (v).begin() , (v).end()
#define popcnt(x) __builtin_popcount(x)
#define inf 0x3f3f3f3f
#define watch(x) cout << (#x) << " is " << (x) << endl

using namespace std;
typedef long long  ll;

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r" , stdin);
#endif
//    ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);
    int t , cs = 1;
    cin >> t;

    while(t--){
        string s;
        cin >> s;

        map<char , int> mp = {{'(' , -1} , {'{' , -2} ,
                                 {'<' , -3} , {'[' , -4} ,
                                    {')' , 1} , {'}' , 2} , {'>' , 3} , {']' , 4}};
        reverse(all(s));
        int n = (int)s.size();
        vector<vector<int> > v(5 , {n});
        vector<int> ans(n + 2 , 0);

        for(int i = 0 ; i < n ; ++i){
            int bracket = mp[s[i]];
            if(bracket > 0){
                v[bracket].pb(i);
            }
            else{
                bracket = -bracket;
                int lst = v[bracket].back();
                bool ok = true;
                for(int j = 1 ; j <= 4 ; ++j){
                    for(int x : v[j]){
                        if(x > lst && x < i)ok = false;
                    }
                }
                if(lst != n && ok){
                    ans[i] = i - lst + 1;
                    ans[i] += (lst ? ans[lst - 1] : 0);
                    v[bracket].pop_back();
                }
                else v.assign(5 , {n});
            }
        }

        printf("Case %d:\n" , cs++);
        for(int i = n - 1 ; i >= 0 ; --i)
            printf("%d\n" , ans[i]);

    }
}

