/*
    first of all what cases are impossible -> if (k > summation of all positive bits) or (k < summation of all negative bits)
    otherwise we can take the summation of all positive bits and check the difference (possum - k) can be made by closing some positive bits
    and opening some negative bit or not
*/
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
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s;
        cin >> s;
        reverse(all(s));

        ll k;
        cin >> k;
        vector<int> bits(n , 0);
        unsigned long long curpos = 0 , curneg = 0;
        for(int i = 0 ; i < n ; ++i){
            if(s[i] == 'p'){
                curpos += (1ULL << i); // take care
//                if(cur > )
                bits[i] = 1;
            }
            else{
                curneg += (1ULL << i);
            }
        }
//        watch(curpos) , watch(curneg);
//        watch(k);
        if((k < 0 && abs(k) > curneg) || (k > 0 && k > curpos)){
            cout << "Impossible\n";
            continue;
        }

        unsigned long long rem = curpos - k;
//        watch(rem);
        vector<int> needed;
        int i = 0;
        while(rem){
            if(rem & 1)needed.pb(i);
            rem >>= 1ULL;
            ++i;
        }
//        for(int x : needed)
//            cout << x << endl;
        bool bad = false;
        for(int x : needed){
            if(x > n - 1){
                bad = true;
            }
        }

        if(bad){
            cout << "Impossible\n";
            continue;
        }


        for(int x : needed){
            if(s[x] == 'p')
                bits[x] = 0;
            else bits[x] = 1;
        }

        reverse(all(bits));
        for(int x : bits)
            cout << x;
        cout << "\n";
    }
}
