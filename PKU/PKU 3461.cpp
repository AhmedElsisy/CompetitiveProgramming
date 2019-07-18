#include <iostream>
#include <vector>
#include <string>
#define pb push_back
#define all(v) (v).begin() , (v).end()
#define popcnt(x) __builtin_popcount(x)
#define inf 0x3f3f3f3f
#define watch(x) cout << (#x) << " is " << (x) << endl
#define rand() (rand() << 15 | rand())
using namespace std;

vector<int> prefix_function(string s){
    int n = (int)s.size();
    vector<int> prefix(n , 0);
    for(int i = 1 ; i < n ; ++i){
        int j = prefix[i - 1];
        while(j > 0 && s[i] != s[j])
            j = prefix[j - 1];
        if(s[i] == s[j])
            ++j;
        prefix[i] = j;
    }
    return prefix;
}

int count_occurences(string P , string T){
    int n = (int)T.size() , cnt = 0;
    vector<int> prefix = prefix_function(P);
    vector<int> match(n , 0);
    for(int i = 0 , j = 0 ; i < n ; ++i){
        while(j > 0 && T[i] != P[j])j = prefix[j - 1];
        if(T[i] == P[j])
            ++j;
        match[i] = j;
        if(j == (int)P.size())++cnt , j = prefix[j - 1];
    }
    return cnt;
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt" , "r" , stdin);
#endif
    ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        string P , T;
        cin >> P >> T;
        cout << count_occurences(P , T) << "\n";
    }
}
