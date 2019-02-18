/*
    initially you have to change all characters that is not 'A' so you have to calculate them
    for each character X you can reach them normally (from 'A' to X) or (from 'A' to 'Z' and 'Z' to X) you add the minimum
    then you have to visit all character that is not 'A' at least once
    let change[] be the array that have the indexes of character that is not 'A'
    lets divide the whole array into to parts possibly one of them is empty
    first part we traverse it from the start of the array and the second part from the end of the array
    try all of them in order O(n)
*/

#include <bits/stdc++.h>

#define pb push_back
#define all(v) (v).begin() , (v).end()
#define popcnt(x) __builtin_popcount(x)
#define inf 0x3f3f3f3f
#define watch(x) cout << (#x) << " is " << (x) << endl

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
        string s;
        cin >> s;

        int ans = 0;
        for(char x : s)
            ans += min(('Z' - x) + 1 , (x - 'A'));

        int n = (int)s.size();
        vector<int> change;
        for(int i = 0 ; i < n ; ++i)
            if(s[i] != 'A')change.pb(i);


        int add = ((int)change.size() != 0 ? inf : 0);
        for(int i = 0 ; i + 1 < (int)change.size() ; ++i){
            int x = change[i];
            add = min(x + x + 1 + ((n - 1) - change[i + 1]) , add);
            add = min(((n - 1) - change[i + 1]) * 2 + 2 + x , add);
        }
        if((int)change.size()){
            add = min(add , change[(int)change.size() - 1]);
            add = min(add , 1 + ((n - 1) - change[0]));
        }
        cout << ans + add << '\n';
    }
}
