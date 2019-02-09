/*
    small observations:
    - abs(a3 - a4) should be in range [0 : 1] otherwise there is no solution
    - if a3 == a4 then the answer will be like 47474.. or 74747..
    - a3 > a4 then the answer will be like 4747.. , a4 > a3 will be like 7474..
    if you build the original string and you still have some 4's and 7's then
    you should put 4's in the first occurrence of 4 and 7's in the last occurrence of 7
    in order to make smallest number
*/
#include <bits/stdc++.h>

#define pb push_back
#define all(v) (v).begin() , (v).end()
#define popcnt(x) __builtin_popcount(x)
#define inf 0x3f3f3f3f
#define watch(x) cout << (#x) << " is " << (x) << endl

using namespace std;
typedef long long  ll;
vector<int> a;
string build(int cnt1 , int cnt2){
    if(cnt1 == cnt2){
        string ret = "";
        if(a[0] >= cnt1 + 1){
            for(int i = 0 ; i < cnt1 ; ++i)
                ret += "47" , a[0]-- , a[1]--;
            ret += "4" , a[0]--;
            return ret;
        }
        else{
            for(int i = 0 ; i < cnt1 ; ++i)
                ret += "74" , a[0]-- , a[1]--;
            ret += "7" , a[1]--;
            return ret;
        }
    }
    string ret = "";
    if(cnt1 > cnt2){
        for(int i = 0 ; i < cnt1 ; ++i)
            ret += "47" , a[0]-- , a[1]--;
    }
    else{
        for(int i = 0 ; i < cnt2 ; ++i)
            ret += "74" , a[0]-- , a[1]--;
    }
    return ret;
}
int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt" , "r" , stdin);
#endif
    ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);
    a.resize(4);
    for(int &x : a)
        cin >> x;

    if(abs(a[2] - a[3]) > 1){
        cout << "-1\n";
        return 0;
    }

    int mx1 = 0 , mx2 = 0;
    string s = "";
    if(a[0] > a[1]){    // build for max a2 , a3 string
        int cnt_4 = a[0] , cnt_7 = a[1];
        while(cnt_4 && cnt_7){
            s += "4";
            cnt_4--;

            s += "7";
            cnt_7--;
        }
        if(cnt_4)s += "4";
    }
    else{
        int cnt_4 = a[0] , cnt_7 = a[1];
        while(cnt_4 && cnt_7){
            s += "7";
            cnt_7--;

            s += "4";
            cnt_4--;
        }
        if(cnt_7)s += "7";
    }

    for(int i = 0 ; i < (int)s.size() ; ++i){
        if(s[i] == '4' && s[i + 1] == '7')mx1++;
        else if(s[i] == '7' && s[i + 1] == '4')mx2++;
    }


    if(a[2] <= mx1 && a[3] <= mx2){
        string ans = build(a[2] , a[3]);
        int lst_7 = -1;
        for(int i = 0 ; i < (int)ans.size() ; ++i)
            if(ans[i] == '7')lst_7 = i;
        for(int i = 0 ; i < (int)ans.size() ; ++i){
            if(ans[i] == '4' && a[0]){
                while(a[0])cout << '4' , a[0]--;
            }
            if(i == lst_7 && a[1]){
                while(a[1])cout << '7' , a[1]--;
            }
            cout << ans[i];
        }
        cout << '\n';
        return 0;
    }
    swap(mx1 , mx2);

    if(a[2] <= mx1 && a[3] <= mx2){
        string ans = build(a[2] , a[3]);
        int lst_7 = -1;
        for(int i = 0 ; i < (int)ans.size() ; ++i)
            if(ans[i] == '7')lst_7 = i;
        for(int i = 0 ; i < (int)ans.size() ; ++i){
            if(ans[i] == '4' && a[0]){
                while(a[0])cout << '4' , a[0]--;
            }
            if(i == lst_7 && a[1]){
                while(a[1])cout << '7' , a[1]--;
            }
            cout << ans[i];
        }
        cout << '\n';
        return 0;
    }
    cout << "-1\n";
}
