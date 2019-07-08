#include <bits/stdc++.h>
#define pb push_back
#define all(v) (v).begin() , (v).end()
#define popcnt(x) __builtin_popcount(x)
#define inf 0x3f3f3f3f
#define watch(x) cout << (#x) << " is " << (x) << endl
#define rand() (rand() << 15 | rand())
using namespace std;
typedef long long  ll;
const int N = 14;

int row[N] , col[N] , n;
int memo[N][N];

int solve(int i , int j){
    if(i == j)
        return 0;
    int &ret = memo[i][j];
    if(~ret)
        return ret;
    ret = INT_MAX;
    for(int k = i ; k < j ; ++k){
        ret = min(ret , solve(i , k) + solve(k + 1 , j) + row[i] * col[k] * col[j]);
    }
    return ret;
}

void printpath(int i , int j){
    if(i == j){
        cout << "A" << i + 1;
        return;
    }

    int mn = INT_MAX;
    int bestk = -1;
    for(int k = i ; k < j ; ++k){
        int cur = solve(i , k) + solve(k + 1 , j) + row[i] * col[k] * col[j];
        if(cur < mn){
            mn = cur;
            bestk = k;
        }
    }

    cout << "(";
    printpath(i , bestk);
    cout << " x ";
    printpath(bestk + 1 , j);
    cout << ")";
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt" , "r" , stdin);
#endif
    ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);
    int cs = 1;
    while(cin >> n){
        if(!n)
            return 0;
        for(int i = 0 ; i < n ; ++i)
            cin >> row[i] >> col[i];

        memset(memo , -1 , sizeof memo);
        cout << "Case " << cs++ << ": ";
        int best = solve(0 , n - 1);
        printpath(0 , n - 1);
        cout << "\n";
    }
}
