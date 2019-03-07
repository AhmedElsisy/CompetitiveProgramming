/*
    winning state is a state that there is at least one sub problem leads to lose the other player
    losing state is a state that there is no sub problem leads to loss the other player
*/
#include <bits/stdc++.h>
#define pb push_back
#define all(v) (v).begin() , (v).end()
#define popcnt(x) __builtin_popcount(x)
#define inf 0x3f3f3f3f
#define watch(x) cout << (#x) << " is " << (x) << endl
#define rand() (rand() << 15 | rand())

using namespace std;
typedef long long  ll;
const int N = 1e6 + 4;
int memo[N] , n , m;
vector<int> a;

int who_wins(int rem){
    int &ret = memo[rem];
    if(~ret)
        return ret;

    ret = 0;
    for(int x : a){
        if(x > rem)continue;
        if(!who_wins(rem - x))
            return ret = 1;
    }

    return ret;
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt" , "r" , stdin);
#endif
    ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);
    while(cin >> n){
        cin >> m;
        a.resize(m);
        for(int &x : a)
            cin >> x;
        memset(memo , -1 , sizeof memo);
        cout << (who_wins(n) ? "Stan wins" : "Ollie wins") << "\n";
    }
}
