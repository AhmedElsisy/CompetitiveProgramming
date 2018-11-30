/*
    you want to choose subset of subjects(m) and choose from each of them
    equal number of specialized members so greedily if you want to take for example group of 3 members
    from a specific subject , you will choose the maximum 3 members have skill value (to maximize total sum)
    let s[x] be the maximum value you can reach if you take groups of size x from subset of subjects
    you will pre-process s[] by sorting members' skills of each subject in descending order
    and for each subject i and for each group x , check if prefixsum[i][x] > 0 then s[x] += prefixsum[i][x]
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
const int N = 1e5 + 4;

vector<int> a[N];
int s[N];

int n , m;
void pre(){
    for(int i = 1 ; i <= m ; ++i)
        sort(all(a[i]) , greater<int>());

    for(int i = 1 ; i <= m ; ++i){
        int sum = 0;
        for(int j = 0 ; j < (int)a[i].size() ; ++j){
            sum += a[i][j];
            if(sum > 0)s[j + 1] += sum;
        }
    }
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r" , stdin);
#endif
    ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);
    cin >> n >> m;
    for(int i = 0 ; i < n ; ++i){
        int S , R;
        cin >> S >> R;
        a[S].pb(R);
    }

    pre();

    int ans = 0;
    for(int i = 1 ; i <= n ; ++i)
        ans = max(ans , s[i]);

    cout << ans << '\n';
}
