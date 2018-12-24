/*
    formal mathematical problem : ((x + y) * (y - x + 1)) / 2 = N , output all possible x , y
    let cur be the current size we will try to form a sum of consecutive elements
    we will try every possible size , what maximum size ? maximum size is maximum M such that M * (M + 1) <= N
    given cur(size of the consecutive elements) we can re write the equation : ((x + y) * cur) / 2 = N
    because cur is the size then (y - x) = cur - 1 and x = -cur + 1 + y
    let S = (x + y) , then S = 2 * N / cur
    and y = (S - cur + 1) / 2 , x = -cur + 1 + y , you need to check if summation between x , y is equal to N
*/

#include <bits/stdc++.h>
#define pb push_back
#define all(v) (v).begin() , (v).end()
#define popcnt(x) __builtin_popcount(x)
#define inf 0x3f3f3f3f
#define watch(x) cout << (#x) << " is " << (x) << endl

using namespace std;
typedef long long  ll;

int dx[] = {0 , 0 , 1 , -1 , 1 , 1 , -1 , -1};
int dy[] = {1 ,-1 , 0 , 0 , -1 , 1 ,  1 , -1};

int main() {
    ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);
    ll N;
    cin >> N;

    vector<pair<ll , ll> > res;
    for(ll cur = 2 ; cur * (cur + 1) / 2 <= N ; ++cur){
        if((N * 2) % cur == 0){
            ll s = N * 2 / cur;
            ll y = (s + cur - 1) / 2;

            ll x = y - cur + 1;

            if((x + y) * cur / 2 == N)res.pb({x , y});
        }
    }

    for(auto e : res)
        cout << e.first << ' ' << e.second << '\n';
}
