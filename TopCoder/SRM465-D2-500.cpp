#include<bits/stdc++.h>
#define pb push_back
#define all(v) (v).begin() , (v).end()
#define popcnt(x) __builtin_popcount(x)
#define inf 0x3f3f3f3f
#define watch(x) cout << (#x) << " is " << (x) << endl
#define rand() (rand() << 15 | rand())
using namespace std;
typedef long long  ll;


class TurretPlacement{
public:
    long long count(vector <int> x, vector <int> y){
        int n = (int)x.size();
        long long ret = 0;
        for(int i = 0 ; i < n ; ++i){
            for(int j = i + 1 ; j < n ; ++j){
                int x0 = x[i] , y0 = y[i];
                int x1 = x[j] , y1 = y[j];
                int dx = (x1 - x0) , dy = (y1 - y0);
                double dist = sqrt(dx * dx + dy * dy);
                int diff = dist * 2.0;
                ret += (1ll * diff * (diff - 1)) / 2ll;
            }
        }
        return ret;
    }
};
