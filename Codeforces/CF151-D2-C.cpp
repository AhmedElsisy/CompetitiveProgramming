#include <bits/stdc++.h>
#define pb push_back
#define all(v) (v).begin() , (v).end()
#define popcnt(x) __builtin_popcount(x)
#define inf 0x3f3f3f3f
#define watch(x) cout << (#x) << " is " << (x) << endl
#define rand() (rand() << 15 | rand())
using namespace std;
typedef long long  ll;

unordered_map<long long , int> memo;

int solve(long long q){
    if(memo.count(q))
        return memo[q];

    int win = false , di = true;
    for(long long d = 2 ; d * d <= q ; ++d){
        if(q % d == 0){
            win |= solve(d);
            if(d != q / d)win |= solve(q / d);
            di = false;
        }
    }
    win |= di;
    return memo[q] = !win;
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt" , "r" , stdin);
#endif
    ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);
    long long q;
    cin >> q;

    int win = solve(q);
    if(win){
        cout << 2 << endl;
    }
    else {
        cout << 1 << endl;
        for(long long d = 2 ; d * d <= q ; ++d){
            if(q % d == 0){
                if(solve(d)){
                    cout << d << endl;
                    return 0;
                }
                if(solve(q / d)){
                    cout << q / d << endl;
                    return 0;
                }
            }
        }
        cout << 0 << endl;
    }
}
