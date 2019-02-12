/*
    ordered set is a policy based data structure
    check this : https://codeforces.com/blog/entry/11080
*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define pb push_back
#define all(v) (v).begin() , (v).end()
#define popcnt(x) __builtin_popcount(x)
#define inf 0x3f3f3f3f
#define watch(x) cout << (#x) << " is " << (x) << endl

using namespace std;
using namespace __gnu_pbds;

typedef long long  ll;

template<typename T>
using ordered_set =
tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt" , "r" , stdin);
#endif
    ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n , m;
        cin >> n >> m;

        vector<int> a(n);
        for(int &x : a)
            cin >> x;

        ordered_set<pair<int , int> > os;
        int curR = -1 , turn = 0;
        while(m--){
            int r;
            cin >> r;
            r--;
            while(curR < r){
                ++curR;
                os.insert({a[curR] , curR});
            }
            cout << (*os.find_by_order(turn)).first << '\n';
            turn++;
        }
        if(t)cout << "\n";
    }
}
