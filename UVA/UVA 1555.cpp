#include <bits/stdc++.h>
#define pb push_back
#define all(v) (v).begin() , (v).end()
#define popcnt(x) __builtin_popcount(x)
#define inf 0x3f3f3f3f
#define watch(x) cout << (#x) << " is " << (x) << endl
#define rand() (rand() << 15 | rand())

using namespace std;
typedef long long  ll;

int n;
double A;
vector<double> a;

bool valid(double mid , double &ret){
    a[1] = mid;
    for(int i = 2 ; i < n ; ++i){
        // h[i] = (h[i - 1] + h[i + 1] / 2) - 1
        // 2h[i] = h[i - 1] + h[i + 1] - 2
        // h[i + 1] = 2h[i] - h[i - 1] + 2
        a[i] = 2 * a[i - 1] - a[i - 2] + 2;
        if(a[i] < 0)return false;
    }
    ret = a[n - 1];
    return true;
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt" , "r" , stdin);
#endif
    ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);
    while(cin >> n >> A){
        a.resize(n);
        a[0] = A;
        int cnt = 100;
        double l = 0 , r = A - 1 , ans = 0;
        while(cnt--){
            double mid = (l + r) / 2 , ret;
            if(valid(mid , ret))ans = ret , r = mid;
            else l = mid;
        }
        cout << fixed << setprecision(2) << ans << "\n";
    }
}

