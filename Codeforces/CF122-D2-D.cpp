/*
    transform all "47" until you face a cycle "447" for example
    if it exists then if you transform it once you get "477" and so on then you stop there and
    don't transform any "47" after this cycle , all you want to know
    after X steps what string the cycle will be?
*/

#include <bits/stdc++.h>

#define pb push_back
#define all(v) (v).begin() , (v).end()
#define popcnt(x) __builtin_popcount(x)
#define inf 0x3f3f3f3f
#define watch(x) cout << (#x) << " is " << (x) << endl

using namespace std;
typedef long long  ll;

string s;
bool bad(int i , int j , string &c){
    return c[i] == '4' && c[j] == '7';
}

void convert(string &c , int i , int j , int x){
    if(x & 1)c[i] = c[j] = '4';
    else c[i] = c[j] = '7';
}

void trans(string &c){
    for(int i = 0 ; i + 1 < (int)c.size() ; ++i){
        if(bad(i , i + 1 , c)){
            convert(c , i , i + 1 , i + 1);
            break;
        }
    }
}
int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt" , "r" , stdin);
#endif
    ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);
    int n , k;
    cin >> n >> k;

    cin >> s;
    int i = 0;
    bool cycle = false;
    for(i = 0 ; i + 1 < n && k ; ++i){
        if(bad(i , i + 1 , s)){
            convert(s , i , i + 1 , i + 1);
            k--;

            if(k && i && bad(i - 1 , i , s)){
                cycle = true;
                break;
            }
        }
    }

    if(!cycle)
        cout << s << '\n';
    else{
        cout << s.substr(0 , i - 1);
        string c = s.substr(i - 1 , 3);
        if(k & 1)trans(c);
        cout << c;
        cout << s.substr(i + 2) << '\n';
    }
}
