/*
    lets sort events ascending by l[i] then in case of equal by r[i]
    so the answer is the maximum subset of this array has no intersection
    lets make dp function(knapsack) for each state i have two choices
    first i leave the current event and call indx + 1
    second i take the current event and call (first indx has l[i] > r[currentindx]) (lowerbound)
    total complexity : O(n lo
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

const int N = 5e5 + 4;
vector<pair<int , int> > a;
int n , memo[N];

int solve(int indx){
    if(indx == n)
        return 0;

    int &ret = memo[indx];
    if(~ret)
        return ret;

    ret = solve(indx + 1);
    int to = lower_bound(all(a) , make_pair(a[indx].S + 1 , -1)) - a.begin();
    ret = max(ret , 1 + solve(to));
    return ret;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r" , stdin);
#endif
    ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);
    cin >> n;
    a.resize(n);

    for(auto &x : a)
        cin >> x.F >> x.S;

    sort(all(a));

    memset(memo , -1 , sizeof memo);
    cout << solve(0) << '\n';
}
