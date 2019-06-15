#include <bits/stdc++.h>
#define pb push_back
#define all(v) (v).begin() , (v).end()
#define popcnt(x) __builtin_popcount(x)
#define inf 0x3f3f3f3f
#define watch(x) cout << (#x) << " is " << (x) << endl
#define rand() (rand() << 15 | rand())
using namespace std;

int maxSubRectSum(vector<vector<int> > &a){
    int n = (int)a.size();
    for(int i = 0 ; i < n ; ++i){
        for(int j = 0 ; j < n ; ++j){
            if(j)a[i][j] += a[i][j - 1];
        }
    }

    int ret = 0; // empty sub-rectangle
    for(int i = 0 ; i < n ; ++i){
        for(int j = i ; j < n ; ++j){
            int currentSum = 0;
            for(int r = 0 ; r < n ; ++r){
                if(i > 0)currentSum += a[r][j] - a[r][i - 1];
                else currentSum += a[r][j];

                if(currentSum < 0)currentSum = 0;
                ret = max(ret , currentSum);
            }
        }
    }

    return ret;
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt" , "r" , stdin);
#endif
    ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);
    int n;
    cin >> n;
    vector<vector<int> > a(n , vector<int>(n));
    for(int i = 0 ; i < n ; ++i){
        for(int j = 0 ; j < n ; ++j){
            cin >> a[i][j];
        }
    }

    cout << maxSubRectSum(a) << "\n";
}
