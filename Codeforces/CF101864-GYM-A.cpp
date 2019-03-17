#include <bits/stdc++.h>
#define pb push_back
#define all(v) (v).begin() , (v).end()
#define popcnt(x) __builtin_popcount(x)
#define inf 0x3f3f3f3f
#define watch(x) cout << (#x) << " is " << (x) << endl
#define rand() (rand() << 15 | rand())

using namespace std;
typedef long long  ll;
vector<ll> pTwo;

void pre(){
    ll c = 1;
    for(int i = 0 ; i < 63 ; ++i)
        pTwo.pb(c) , c *= 2;
}

//int w[10000];
//void getPattern(){
//        for(int i = 1 ; i <= 1000 ; ++i){
//        queue<int> q;
//        for(int j = 1 ; j <= i ; ++j)
//            q.push(j);
//
//        while(q.size() > 1){
//            int p1 = q.front();
//            q.pop();
//            int p2 = q.front();
//            q.pop();
//            q.push(p1);
//        }
//        w[i] = q.front();
//    }
//}

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt" , "r" , stdin);
#endif
    int t , cs = 1;
    cin >> t;
    pre();
//    getPattern();
    while(t--){
        ll x , L , N;
        cin >> x >> L >> N;
        int l = upper_bound(all(pTwo) , max(x , L)) - pTwo.begin() , r = upper_bound(all(pTwo) , N) - pTwo.begin();
        --r;
        long long occured = 0;
//        watch(l) , watch(r);
        if(l > r){
            if(x & 1){
                long long A = (L - pTwo[l - 1]) * 2 + 1;
                long long B = (N - pTwo[r]) * 2 + 1;
                occured += (x >= A && x <= B);
            }
        }
        else{
            occured = (r - l) * (x & 1);
            if(x & 1){
                occured += (((L - pTwo[l - 1]) * 2 + 1) <= x && (pTwo[l] - 1 - pTwo[l - 1]) * 2 + 1 >= x);
                occured += ((N - pTwo[r]) * 2 + 1) >= x;
            }
        }
        long long up = occured + max(0ll , x - L);
//        long long tst = 0;
//        for(int i = L ; i <= N ; ++i)
//            tst += (w[i] == x);
//        watch(occured) , watch(tst);
//        if(tst != occured)
//            puts("WRONG");
        long long down = (N - L + 1);


        long long gcd = __gcd(up , down);
        printf("Case %d: " , cs++);
        cout << up / gcd << "/" << down / gcd << "\n";
    }
}
