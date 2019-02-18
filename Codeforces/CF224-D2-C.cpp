/*
    let bad[] be an indicator if this index is valid for a substring balanced sequence
    bad[i] = true , if it is an opening bracket and there is no closing bracket for it
    OR it is a closing bracket and there is no valid opening bracket for it
    so that the balanced substrings is between any two bad indexes
    just iterate over them and maximize the answer
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

void clear_stack(stack<pair<char , int> > &st , vector<bool> &bad){
    while(!st.empty()){
        bad[st.top().second] = true;
        st.pop();
    }
}

int get_sum(int l , int r , vector<int> v){
    if(r < l)return 0;
    return (l == 0 ? v[r] : v[r] - v[l - 1]);
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt" , "r" , stdin);
#endif
    ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);
    string s;
    cin >> s;
    int n = (int)s.size();

    stack<pair<char , int> > st;
    map<char , char> closeit;
    vector<bool> bad(n + 1 , false);
    closeit[')'] = '(';
    closeit[']'] = '[';

    for(int i = 0 ; i < n ; ++i){
        char x = s[i];
        if(!closeit.count(x)){
            st.push({x , i});
        }
        else{
            char y = closeit[x];
            if(st.empty() || st.top().first != y){
                bad[i] = true;
                clear_stack(st , bad);
            }
            else{
                st.pop();
            }
        }
    }

    clear_stack(st , bad);

    vector<int> v(n , 0);

    for(int i = 0 ; i < n ; ++i)
        v[i] = (!i ? 0 : v[i - 1]) + (s[i] == '[');

    int mx = 0 , l = -1 , r = -1 , lst = -1;
    bad[n] = true;
    for(int i = 0 ; i <= n ; ++i){
        if(bad[i]){
            int cur = get_sum(lst + 1 , i - 1 , v);
            if(cur > mx){
                mx = cur;
                l = lst + 1 , r = i - 1;
            }
            lst = i;
        }
    }

    cout << mx << "\n";
    if(mx)cout << s.substr(l , r - l + 1);
    cout << "\n";
}
