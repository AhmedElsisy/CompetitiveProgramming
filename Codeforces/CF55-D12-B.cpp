/*
    what about try all possible ways and minimize the final answer
    using backtracking we can try all possible ways
*/

#include <bits/stdc++.h>
#define pb push_back
#define all(v) (v).begin() , (v).end()
#define popcnt(x) __builtin_popcount(x)
#define inf 0x3f3f3f3f
#define watch(x) cout << (#x) << " is " << (x) << endl

using namespace std;
typedef long long  ll;
vector<ll> numbers;
vector<char> sym;
ll mn = LLONG_MAX;


void solve(int indx){
    if(indx == 3){
        mn = min(mn , numbers[0]);
        return;
    }

    for(int i = 0 ; i < (int)numbers.size() ; ++i){
        for(int j = i + 1 ; j < (int)numbers.size() ; ++j){
            ll s = (sym[indx] == '*' ? numbers[i] * numbers[j] : numbers[i] + numbers[j]);
            vector<ll> newOne;
            for(int k = 0 ; k < (int)numbers.size() ; ++k){
                if(k == i || k == j)continue;
                newOne.pb(numbers[k]);
            }
            newOne.pb(s);
            swap(numbers , newOne);
            solve(indx + 1);
            swap(numbers , newOne);
        }
    }

}
int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r" , stdin);
#endif
    ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);
    for(int i = 0 ; i < 4 ; ++i){
        ll x;
        cin >> x;
        numbers.pb(x);
    }

    for(int i = 0 ; i < 3 ; ++i){
        char x;
        cin >> x;
        sym.pb(x);
    }

    solve(0);

    cout << mn << '\n';
}

