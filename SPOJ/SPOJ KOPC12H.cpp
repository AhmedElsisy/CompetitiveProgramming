/*
    using digit dp we can count number of element satisfy digit conditions in range [a , b]
*/

#include <bits/stdc++.h>
#define pb push_back
#define all(v) (v).begin() , (v).end()
#define popcnt(x) __builtin_popcount(x)
#define inf 0x3f3f3f3f
#define watch(x) cout << (#x) << " is " << (x) << endl

using namespace std;
typedef long long  ll;

int memo[10][90][90][2];
string s;
int solve(int indx , int Esum , int Osum , bool gr){
    if(indx == (int)s.size())
        return Esum > Osum;

    int &ret = memo[indx][Esum][Osum][gr];
    if(~ret)
        return ret;

    ret = 0;
    int theOne = s[indx] - '0';

    for(int digit = 0 ; digit <= (gr ? 9 : theOne) ; ++digit){
        if(digit & 1)ret += solve(indx + 1 , Esum , Osum + digit , gr | (digit < theOne));
        else ret += solve(indx + 1 , Esum + digit , Osum , gr | (digit < theOne));
    }

    return ret;
}


int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r" , stdin);
#endif
    ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);
    int t;
    cin >> t;
    while(t--){

        int a , b;
        cin >> a >> b;

        string A , B;
        A = to_string(a - 1);
        B = to_string(b);

        memset(memo , -1 , sizeof memo);
        s = B;
        int ans = solve(0 , 0 , 0 , false);
        memset(memo , -1 , sizeof memo);
        s = A;
        ans -= solve(0 , 0 , 0 , false);

        cout << ans << '\n';
    }
}

