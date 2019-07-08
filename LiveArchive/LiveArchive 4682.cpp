#include <bits/stdc++.h>
#define pb push_back
#define all(v) (v).begin() , (v).end()
#define popcnt(x) __builtin_popcount(x)
#define inf 0x3f3f3f3f
#define watch(x) cout << (#x) << " is " << (x) << endl
#define rand() (rand() << 15 | rand())
using namespace std;
typedef long long  ll;
const int N = 2e6 + 4;

int trie[N][2] , sz = 1;

void add(int x){
    bitset<32> bt = x;
    string s = bt.to_string();
    int cur = 0;
    for(char c : s){
        if(trie[cur][c - '0'] == -1){
            trie[cur][c - '0'] = sz;
            memset(trie[sz] , -1 , sizeof trie[sz]);
            ++sz;
        }
        cur = trie[cur][c - '0'];
    }
}

int getMax(int x){
    bitset<32> bt = x;
    string s = bt.to_string();
    int ret = 0 , i = 31;
    int cur = 0;
    for(char c : s){
        int bit = c - '0';
        if(trie[cur][!bit] != -1){
            cur = trie[cur][!bit];
            ret |= (1 << i);
        }
        else cur = trie[cur][bit];
        --i;
    }
    return ret;
}

void init(){
    sz = 1;
    memset(trie[0] , -1 , sizeof trie[0]);
}

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
        init();
        vector<int> a(n);
        for(int &x : a)
            cin >> x;

        add(0);
        int cur = 0 , mx = 0;
        for(int x : a){
            cur ^= x;
            mx = max(mx , getMax(cur));
            add(cur);
        }

        cout << mx << "\n";
    }


}
