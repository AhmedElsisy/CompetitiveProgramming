#include <bits/stdc++.h>
#define pb push_back
#define all(v) (v).begin() , (v).end()
#define popcnt(x) __builtin_popcount(x)
#define inf 0x3f3f3f3f
#define watch(x) cout << (#x) << " is " << (x) << endl
#define rand() (rand() << 15 | rand())

using namespace std;
typedef long long  ll;

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt" , "r" , stdin);
#endif
    ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);
    int cows , cars , show;
    while(cin >> cows >> cars >> show){

        int n = cars + cows;
        double ans = ((1.0 * cows / n) * (1.0 * cars / (n - 1 - show))) +
                            ((1.0 * cars / n) * (1.0 *(cars - 1) / (n - 1 - show)));
        cout << fixed << setprecision(5) << ans << "\n";
    }
}
