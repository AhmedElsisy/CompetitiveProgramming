#include <bits/stdc++.h>
#define pb push_back
#define all(v) (v).begin() , (v).end()
#define popcnt(x) __builtin_popcount(x)
#define inf 0x3f3f3f3f
#define watch(x) cout << (#x) << " is " << (x) << endl
#define rand() (rand() << 15 | rand())
using namespace std;

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt" , "r" , stdin);
#endif
    ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);
    int t , cs = 1;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> h(n) , w(n);
        for(int &x : h)
            cin >> x;
        for(int &x : w)
            cin >> x;

        vector<int> I(n);
        for(int i = 0 ; i < n ; ++i){
            I[i] = w[i];
            for(int j = 0 ; j < i ; ++j){
                if(h[i] > h[j])I[i] = max(I[i] , I[j] + w[i]);
            }
        }

        vector<int> D(n);
        for(int i = 0 ; i < n ; ++i){
            D[i] = w[i];
            for(int j = 0 ; j < i ; ++j){
                if(h[i] < h[j])D[i] = max(D[i] , D[j] + w[i]);
            }
        }

        int i = *max_element(all(I)) , d = *max_element(all(D));
        if(i >= d)
            printf("Case %d. Increasing (%d). Decreasing (%d).\n" , cs++ , i , d);
        else
            printf("Case %d. Decreasing (%d). Increasing (%d).\n" , cs++ , d , i);
    }
}
