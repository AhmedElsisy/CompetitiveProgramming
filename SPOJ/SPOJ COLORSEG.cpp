/*
    using dp we can count number of sequences satisfy problem's criteria
    in each index we try to put any number from 1 to m let x be the new number in the current indx
    s.t. gcd((x + lst chosen element) , (lst chosen + before lst)) == 1
    so we have to put lst element and before lst element in our state in dp
*/

#include <bits/stdc++.h>
#define pb push_back
#define all(v) (v).begin() , (v).end()
#define popcnt(x) __builtin_popcount(x)
#define inf 0x3f3f3f3f
#define watch(x) cout << (#x) << " is " << (x) << endl

using namespace std;
typedef long long  ll;
const int N = 51 , MOD = 1000003;

int memo[N][N][N][N] , n , m;
int g[104][104];

int add(int a , int b){
    a %= MOD;
    b %= MOD;
    return (1ll * a + b) % MOD;
}

int solve(int indx , int lst1 , int lst2 , int M){
    if(indx == -1)
        return 1;

    int &ret = memo[indx][lst1][lst2][M];
    if(~ret)
        return ret;

    ret = 0;
    if(lst1 == 0 || lst2 == 0){
        if(lst1 == 0)
            for(int i = 1 ; i <= M ; ++i)ret = add(ret , solve(indx - 1 , i , 0 , M));
        else for(int i = 1 ; i <= M ; ++i)ret = add(ret , solve(indx - 1 , lst1 , i , M));
        return ret;
    }
    for(int i = 1 ; i <= M ; ++i)
        if(g[lst1 + lst2][lst2 + i] == 1)ret = add(ret , solve(indx - 1 , lst2 , i , M));
    return ret;
}


void pre(){
    for(int i = 1 ; i <= 100 ; ++i){
        for(int j = 1 ; j <= 100 ; ++j){
            g[i][j] = __gcd(i , j);
        }
    }
}
int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r" , stdin);
#endif

    pre();
    memset(memo , -1 , sizeof memo);
    int t , cs = 1;
    scanf("%d" , &t);
    while(t--){
        scanf("%d %d" , &n , &m);
        printf("Case %d: %d\n" , cs++ , solve(n - 1 , 0 , 0 , m));
    }

}
