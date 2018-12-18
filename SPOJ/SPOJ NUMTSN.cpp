/*
    using digit dp we can calculate number of elements from range [A : B] has some property
    our property is this problem is number of 3s equals to 6s equals to 9s
    then naive dp state is state(indx , cnt3 , cnt6 , cnt9 , gr(boolean)) this will take time limit
    51 * 18 * 18 * 18 * 2 = 594864 * 10 (number of digit value loop inside the dp) = 5948640 * 100(test cases) = 594864000 ~= 6e8
    time limit : 0.391s
    then we can optimize this state , instead of cnt3 , cnt6 , cnt9
    we can save only the difference between 3 counters
    to do this we can save the difference between cnt3 and one of others
    and difference between cnt3 and the other one
    then the complexity : 51 * 36 * 36 * 2 * 2 (added boolean to check if we take 3 or 6 or 9)
*/

#include <bits/stdc++.h>
#define pb push_back
#define all(v) (v).begin() , (v).end()
#define popcnt(x) __builtin_popcount(x)
#define inf 0x3f3f3f3f
#define watch(x) cout << (#x) << " is " << (x) << endl

using namespace std;
typedef long long  ll;
const int N = 52 , M = 18 , MOD = 1000000007;

int memo[N][37][37][2][2];
string s;

int add(int a , int b){
    return (1ll * a + b) % MOD;
}

int sz;

int solve(int indx , int c36 , int c39 , bool gr , bool taked){
    if(indx == -1)
        return !c36 && !c39 && taked;

    int &ret = memo[indx][c36 + 18][c39 + 18][gr][taked];
    if(~ret)
        return ret;
    ret = 0;

    int theOne = s[indx] - '0';

    for(int digit = 0 ; digit <= (gr ? 9 : theOne) ; ++digit){
        if(digit == 3 && c36 < 17 && c39 < 17)ret = add(ret , solve(indx - 1 , c36 + 1 , c39 + 1 , gr | (digit < theOne) , true));
        else if(digit == 6 && c36 > -17)ret = add(ret , solve(indx - 1 , c36 - 1 , c39 , gr | (digit < theOne) , true));
        else if(digit == 9 && c39 > -17)ret = add(ret , solve(indx - 1 , c36 , c39 - 1 , gr | (digit < theOne) , true));
        else ret = add(ret , solve(indx - 1 , c36 , c39 , gr | (digit < theOne) , taked));
    }

    return ret;
}


void dec(string &s)
{
    int pos = s.length() - 1;
    s[pos]--;
    while(s[pos] < '0')
    {
        s[pos] = '9';
        s[--pos]--;
    }
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r" , stdin);
#endif
    int t;
    scanf("%d", &t);
    while(t--){

        string a , b;
        char tmp[51];
        scanf("%s" , tmp);
        a = tmp;
        scanf("%s" , tmp);
        b = tmp;

        dec(a);
        reverse(all(a));
        reverse(all(b));

        memset(memo , -1 , sizeof memo);

        s = b;
        int ans = solve((int)s.size() - 1 , 0 , 0 , false , false);

        memset(memo , -1 , sizeof memo);

        s = a;
        ans -= solve((int)s.size() - 1 , 0 , 0 , false , false);

        if(ans < 0)ans += MOD;
        printf("%d\n" , ans);
    }
}
