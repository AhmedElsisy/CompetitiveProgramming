
/*
    sieve and for each prime p you iterate over its multiples
    then between every two adjacent multiples you have to choose what cost
    you will pay to make every element between that two adjacent multiples multiple to prime p
    let cnt[i] be the count of numbers from 1 to i in the array
    let sum[i] be the sum of numbers 1 to i in the array
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

const int N = 1e7 + 44;

ll cnt[N] , sum[N] , cost[N];
int n , x , y;

vector<int> primes;
bitset<N> p;

int getmedian(int f , int s){
    int l = f , r = s , ans = f - 1;
    while(l <= r){
        int mid = (l + r) >> 1;
        if(1ll * y * (s - mid) <= x)r = mid - 1;
        else ans = mid , l = mid + 1;
    }
    return ans;
}

void sieve(){
    p.set();
    p[0] = p[1] = 0;
    for(int i = 2 ; i < N ; ++i){
        if(p[i]){
            int f = 0 , s = i;
            for(int j = i ; j < N ; j += i){
                p[j] = 0;
                int m = getmedian(f + 1 , s);
                cost[i] += 1ll * (cnt[m] - cnt[f]) * x;
                int k = cnt[s] - cnt[m];
                cost[i] += 1ll * (1ll * s * k - (sum[s] - sum[m])) * y;
                f = j , s = j + i;
            }
            primes.pb(i);
        }
    }
}
int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r" , stdin);
#endif
    ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);
    cin >> n >> x >> y;

    vector<int> a(n);
    for(int &x : a)
        cin >> x , cnt[x]++ , sum[x] += x;

    partial_sum(cnt , cnt + N , cnt);
    partial_sum(sum , sum + N , sum);

    sieve();

    ll ans = LLONG_MAX;
    for(int x : primes)
        ans = min(ans , cost[x]);

    cout << ans << '\n';
}
