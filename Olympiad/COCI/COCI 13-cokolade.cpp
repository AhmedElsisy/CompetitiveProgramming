/*
    let N be size of the array and V largest value in the array
    lets define Important numbers for value X as numbers has unique quotient with X (and has minimal possible value)
    so that we reduce the search space from N * (V + 1) into N * sqrt(V)
    because each element has at most sqrt(V) important numbers
    do brute force.
*/

#include <bits/stdc++.h>
#define pb push_back
#define all(v) (v).begin() , (v).end()
#define popcnt(x) __builtin_popcount(x)
#define inf 0x3f3f3f3f
#define watch(x) cout << (#x) << " is " << (x) << endl

using namespace std;
typedef long long  ll;
const int N = 104;

int main() {
    freopen("input.txt" , "r" , stdin);
    int n;
    cin >> n;

    vector<int> a(n);
    for(int &x : a)
        cin >> x;

    vector<int> v;

    for(int i = 0 ; i < n ; ++i){
        int E = 1;

        while(1){
            v.pb(E);
            if(a[i] / E == 0)break;
            E = (a[i] / (a[i] / E) + 1);
        }
    }

	sort(all(v));
	v.resize(unique(all(v)) - v.begin());

	vector<int> divs;
	vector<int> cnt(n + 1 , inf);
	for(int x : v){
        divs.resize(n);
        for(int i = 0 ; i < n ; ++i)
            divs[i] = a[i] / x;

        sort(all(divs));
        for(int i = 0 ; i < (int)divs.size() ; ++i){
            int j = i;
            while(j < n && divs[i] == divs[j])++j;
            cnt[j - i] = min(cnt[j - i] , x);
            i = j - 1;
        }

	}


	for(int i = 1 ; i <= n ; ++i){
        cout << (cnt[i] == inf ? -1 : cnt[i]) << '\n';
	}
}
