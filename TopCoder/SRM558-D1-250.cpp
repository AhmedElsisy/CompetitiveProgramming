#include<bits/stdc++.h>
#define pb push_back
#define all(v) (v).begin() , (v).end()
#define popcnt(x) __builtin_popcount(x)
#define inf 0x3f3f3f3f
#define watch(x) cout << (#x) << " is " << (x) << endl
#define rand() (rand() << 15 | rand())
using namespace std;
typedef long long  ll;
const int N = 53;
string s;
int cost , len;
string colors = "*RGB";
map<char , int> mp;

int memo[N][N][4];

int solve(int indx , int rem , int col){
    if(indx == (int)s.size())
        return 0;
    int &ret = memo[indx][rem][col];
    if(~ret)
        return ret;

    ret = inf;
    set<char> uni;
    int cnt = 0;
    if(col)uni.insert(colors[col]);
    for(int i = indx ; i < (int)s.size() && i <= indx + len - 1 ; ++i){
        if(s[i] != '*'){
            uni.insert(s[i]);
        }
        ++cnt;
    }

    if(cnt == len){
        if(uni.size() == 1){
            ret = min(ret , cost + solve(indx + 1 , len - 1 , (len == 1 ? 0 : mp[*uni.begin()])));
        }
        else if(uni.empty()){
            for(int i = 1 ; i <= 3 ; ++i)
                ret = min(ret , cost + solve(indx + 1 , len - 1 , (len == 1 ? 0 : i)));
        }
    }

    if(rem)ret = min(ret , solve(indx + 1 , rem - 1 , (rem == 1 ? 0 : col)));
    return ret;
}

class Stamp{
public:
    int getMinimumCost(string desiredColor, int stampCost, int pushCost){
        s = desiredColor;
        cost = pushCost;
        mp['R'] = 1;
        mp['G'] = 2;
        mp['B'] = 3;
        int ret = inf;
        for(int i = 1 ; i <= (int)s.size() ; ++i){
            memset(memo , -1 , sizeof memo);
            len = i;
            ret = min(ret , i * stampCost + solve(0 , 0 , 0));
        }
        return ret;
    }
};
