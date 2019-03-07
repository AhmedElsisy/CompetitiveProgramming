/*
    State : dp(int leftArray , int RightArray)
    Transition : you have to choices you take the leftmost element or the rightmost
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

const int N = 53;

vector<int> a;
int memo[N][N];
int solve(int l , int r){
    if(l > r)
        return 0;

    int &ret = memo[l][r];
    if(~ret)
        return ret;

    ret = -inf;
    ret = max(ret , a[l] + (-solve(l + 1 , r)));
    ret = max(ret , a[r] + (-solve(l , r - 1)));

    return ret;
}

class BagsOfGold{
public:
    int netGain(vector<int> bags){
        a = bags;
        int n = a.size();
        memset(memo , -1 , sizeof memo);
        return solve(0 , n - 1);
    }
};
