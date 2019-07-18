#include<bits/stdc++.h>
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
    int t , cs = 1;
    cin >> t;
    while(t--){
        string str;
        int x;
        cin >> x >> str;

        int k = (int)str.size();
        vector<int> cnt(1003 , 0);

        int i = 0;
        while(x - i * k > 0){
            int num = x - i * k;
            for(int j = 2 ; 1ll * j * j <= num ; ++j){
                while(num % j == 0)num /= j , cnt[j]++;
            }
            if(num > 1)cnt[num]++;
            ++i;
        }

        ll res = 1;
        bool flag = false;
        for(int i = 0 ; i <= 1000 ; ++i)
            flag |= __builtin_mul_overflow(res ,(cnt[i] + 1) , &res);
        cout << "Case " << cs++ << ": ";
        if(flag || res > (ll)1e18)
            cout << "Infinity\n";
        else cout << res << "\n";
    }
}
