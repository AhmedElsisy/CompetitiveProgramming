/*
    let solve(msk , t) be the state of the game (winning state or losing state)
    with mask msk which contains the state of every cell in the board
    if it is empty or not and integer t which indicates which player should play currently
    transition : try all possible sub arrays which is valid to take in the current turn
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
const int N = (1 << 14) + 4;
string s;
int memo[N][2] , n;

int r(int i){
    return n - 1 - i;
}

int solve(int msk , int t){
    if(popcnt(msk) == n - 1){
        for(int i = 0 ; i < n ; ++i){
            if(!(msk & (1 << r(i))))
                return (s[i] - 'A' == t);
        }
    }

    int &ret = memo[msk][t];
    if(~ret)
        return ret;

    ret = 0;
    for(int i = 0 ; i < n ; ++i){
        int newMsk = msk;
        for(int j = i ; j < n && !(msk & (1 << r(j))) ; ++j){
            newMsk |= (1 << r(j));
            if(popcnt(newMsk) != n)ret |= (!solve(newMsk , !t));
        }
    }

    return ret;
}

class RowAndCoins{
public:
    string getWinner(string cells){
        n = (int)cells.size();
        s = cells;
        // alice starts

        memset(memo , -1 , sizeof memo);

        return (solve(0 , 0) ? "Alice" : "Bob");
    }
};
