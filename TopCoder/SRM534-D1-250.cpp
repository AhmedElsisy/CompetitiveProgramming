/*
    dp state : mask contains checkers locations
    transition : try to move/jump each valid checker
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

const int N = (1 << 20) + 4;

int memo[N] , n;

bool exist(int i , int msk){
    return msk & (1 << i);
}

int c(int i){
	return n - 1 - i;
}

int solve(int msk){

    int &ret = memo[msk];
    if(~ret)
        return ret;

    ret = 0;
    for(int i = 0 ; i < n ; ++i){
        if(exist(c(i) , msk)){
            // jump
            if(i + 3 < n && exist(c(i + 1) , msk) && exist(c(i + 2) , msk) && !exist(c(i + 3) , msk)){
                int newMsk = msk ^ (1 << c(i));
                if(i + 3 < n - 1)newMsk |= (1 << c(i + 3));
                ret |= (!solve(newMsk));
            }
            if(i + 1 < n && !exist(c(i + 1) , msk)){
                int newMsk = msk ^ (1 << c(i));
                if(i + 1 < n - 1)newMsk |= (1 << c(i + 1));
                ret |= (!solve(newMsk));
            }
        }
    }
    return ret;
}

class EllysCheckers{
public:
    string getWinner(string board){
    	n = (int)board.size();
    	int msk = 0;
    	for(int i = 0 ; i < n - 1 ; ++i){
            if(board[i] == 'o'){
                msk |= (1 << c(i));
            }
        }
        memset(memo , -1 , sizeof memo);
        return (solve(msk) ? "YES" : "NO");
    }

};
