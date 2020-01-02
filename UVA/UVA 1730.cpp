/**
 *      link: https://onlinejudge.org/external/17/1730.pdf
 *      - sum of divisors of a number is multiplication of sum all powers of each prime for example 6 {2^1 , 3^1}
 *      the sum is (2^0 + 2^1) * (3^0 + 3^1) , or it can be found in a trivial way by getting the divisors of the number in O(sqrt(N))
 *      complexity of this : iterating over each i <= N and factorize this number and calculate sum of divisors O(N * (factorize each(i)))
 *
 *      - updated version of complexity using contribution to sum the complexity is reduced to O(N)
 *      for each i <= N you want to calculate how many times it will be a divisor for a number [2:N] it will be floor(N / i)
 *      so add (i * (N / i)) but still got TLE
 *
 *      - pre-process these calculation for all N <= 2e7 and got AC (around 3e8 operations) O(N log N)
 *      for each number iterate over its multiplies and add its value into ans[multiple] and do a prefix sum of the array ans[]
 *      the answer is ans[n] - 1 (because we are not considering {1} in [2:N])
 */
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define all(v) (v).begin() , (v).end()
#define popcnt(x) __builtin_popcount(x)
#define inf 0x3f3f3f3f
#define watch(x) cout << (#x) << " is " << (x) << endl
#define rand() (rand() << 15 | rand())
using namespace std;
using namespace __gnu_pbds;

template<typename T>
using ordered_set =
tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

typedef long long  ll;
#define EPS 1e-9
#define PI acos(-1.0)

const int N = 2e7 + 1;
ll ans[N];
int main() {
#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
#endif
   ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
   for(ll i = 1 ; i < N ; ++i){
      for(int j = i ; j < N ; j += i)
         ans[j] += i;
   }
   partial_sum(ans , ans + N , ans);
   ll n;
   while(cin >> n && n) {
      cout << ans[n] - 1 << "\n";
   }
}