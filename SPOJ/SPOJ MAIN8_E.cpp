/*
    let's try to match the smaller string SEQ from every character in large string S
    if and only if this character is equal to first character in SEQ
    in matching we greedily try to take closest element equals to specific character we want to match
    let go(lst , i) be the minimum index we will try to get to match from i to end of SEQ
    and lst is the index of last character taken in this subsequence (to take the next element after this)
*/

#include <bits/stdc++.h>
#define pb push_back
#define all(v) (v).begin() , (v).end()
#define popcnt(x) __builtin_popcount(x)
#define inf 0x3f3f3f3f
#define watch(x) cout << (#x) << " is " << (x) << endl

using namespace std;
typedef long long  ll;

string s , seq;
vector<int> v[30];


int go(int lst , int i){
    if(i == (int)seq.size())
        return lst;
    auto it = upper_bound(all(v[seq[i] - 'a']) , lst);
    return (it != v[seq[i] - 'a'].end() ? go(*it , i + 1) : -1);
}


int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r" , stdin);
#endif
    ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        for(int i = 0 ; i < 30 ; ++i)
            v[i].clear();

        cin >> s >> seq;
        for(int i = 0 ; i < (int)s.size() ; ++i){
            v[s[i] - 'a'].pb(i);
        }

        int ans = inf;
        for(int i = 0 ; i < (int)s.size() ; ++i){

            int j = -1;
            if(s[i] == seq[0])j = go(i , 1);
            if(~j)ans = min(ans , j - i + 1);
        }

        cout << (ans >= inf ? -1 : ans) << '\n';
    }
}

