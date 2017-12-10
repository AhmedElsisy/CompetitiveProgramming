#include <bits/stdc++.h>
#define pb push_back
#define inf 0x3f3f3f3f
#define all(v) (v).begin() , (v).end()

using namespace std;

typedef vector<int> vi;
typedef long long   ll;

int dx[] = {0 , 0 , 1 , -1 , 1 , 1 , -1 , -1};
int dy[] = {1 ,-1 , 0 , 0 , -1 , 1 ,  1 , -1};
const int N = 101;
ll memo[N][N];

const int MOD = 1000000;

ll solve(int n,int k){
    if(n < 0 || k < 0)
        return 0;
    if(k == 0){
        if(n == 0)
            return 1;
        return 0;
    }
    if(memo[n][k] != -1)
        return memo[n][k];
    memo[n][k] = 0;
    for(int i=0;i<=n;++i){
        memo[n][k] += (solve(n - i , k-1 ) % MOD);
    }
    return memo[n][k]%MOD;
}


int main()
{
    int n,k;
    while(scanf("%d %d",&n,&k)){
        if(!n&&!k)
            return 0;
        memset(memo,-1,sizeof memo);
        ll ans = solve(n,k);
        cout<<ans%MOD<<endl;
    }
    return 0;
}
