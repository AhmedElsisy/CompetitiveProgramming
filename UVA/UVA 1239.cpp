/*
    for each index try to expand left and right trying to make a palindrome
    there are two types of expanding
        1) the palindrome will be odd size
        2) the palindrome will be even size
    it's easy to implement it as a window trying to increase it's size in order to using at most k characters
    expanding will be like decrease the remaining k if : element in the left of the window doesn't equal to the right one
    otherwise continue with the same k
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

string s;
int k;

int checkOdd(int i){
    int l = i - 1 , r = i + 1;
    int remK = k , cnt = 0;
    while(l >= 0 && r < (int)s.size()){
        if(s[l] != s[r] && !remK)
            break;
        ++cnt;
        remK -= (s[l] != s[r]);
        l-- , r++;
    }
    return cnt * 2 + 1;
}

int checkEven(int i){
    int l = i , r = i + 1;
    int remK = k , cnt = 0;
    while(l >= 0 && r < (int)s.size()){
        if(s[l] != s[r] && !remK)
            break;
        ++cnt;
        remK -= (s[l] != s[r]);
        l-- , r++;
    }
    return cnt * 2;
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt" , "r" , stdin); // remember to delete
#endif
    ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        cin >> s >> k;

        int mx = 0;
        for(int i = 0 ; i < (int)s.size() ; ++i)
            mx = max({mx , checkEven(i) , checkOdd(i)});

        cout << mx << "\n";
    }

}
