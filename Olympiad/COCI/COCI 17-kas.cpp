/*
    instead of track sum of each person we will track the difference between them
*/
#include <bits/stdc++.h>
#define pb push_back
#define all(v) (v).begin() , (v).end()
#define popcnt(x) __builtin_popcount(x)
#define inf 0x3f3f3f3f
#define watch(x) cout << (#x) << " is " << (x) << endl

using namespace std;
typedef long long  ll;
const int N = 505 , M = 1e5 + 4;
int n , memo[N][M];
vector<int> a;

int solve(int indx , int s){
    if(indx == n){
        return (!s ? 0 : -inf);
    }

    int &ret = memo[indx][s];
    if(~ret)
        return ret;

    ret = -inf;
    ret = max(ret , a[indx] + solve(indx + 1 , s + a[indx]));
    ret = max(ret , max(0, a[indx] - s) + solve(indx + 1 , abs(s - a[indx])));
    ret = max(ret , solve(indx + 1 , s));
    return ret;
}
int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r" , stdin);
#endif
    ios::sync_with_stdio() , cin.tie(0) , cout.tie();
    int tot = 0;
    cin >> n;
    a.resize(n);
    for(int &x : a)
        cin >> x , tot += x;
    memset(memo , -1 , sizeof memo);
    int v = solve(0 , 0);
    cout << v + (tot - 2 * v) << '\n';
}
