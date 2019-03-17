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
//    ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);
    int n , r , cs = 1;
    while(cin >> n >> r){
        if(!n && !r)
            break;
        vector<double> a(n) , res(n);
        for(auto &x : a)
            cin >> x;
        double B = 0.0;
        for(int i = 0 ; i < (1 << n) ; ++i){
            int msk = i;
            if(popcnt(msk) != r)continue;
            double P = 1.0;
            for(int j = 0 ; j < n ; ++j){
                if(msk & (1 << j))P *= a[j];
                else P *= (1 - a[j]);
            }
            B += P;
            for(int j = 0 ; j < n ; ++j){
                if(msk & (1 << j))res[j] += P;
            }
        }
        printf("Case %d:\n" , cs++);
        for(int i = 0 ; i < n ; ++i)
            cout << fixed << setprecision(6) << res[i] / B << "\n";
    }
}
