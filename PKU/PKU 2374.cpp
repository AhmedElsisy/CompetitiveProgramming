/*
    dp(indx , t) means that you are in fence #indx and your in left side of the fence or the right according to variable t
    0 stands for left , 1 stands for right
    we use segment tree to know what the first fence we will face if we move vertically from one of current fence sides
    pre-process costs for each indx what number of movements we will take if we move from current fence to another fence sides
*/
#include <iostream>
#include <vector>
#include <cstring>

#define pb push_back
#define all(v) (v).begin() , (v).end()
#define popcnt(x) __builtin_popcount(x)
#define inf 0x3f3f3f3f
#define watch(x) cout << (#x) << " is " << (x) << endl
#define rand() (rand() << 15 | rand())

using namespace std;
typedef long long  ll;
const int N = 50005 , M = 2e5 + 4;

int st[4 * M] , lz[4 * M] , n , s , cost[N][2][2] , nxt[N][2];
int SHIFT = 1e5 + 1;

void propagate(int p){
    if(!lz[p])return;
    st[2 * p] = lz[p];
    st[2 * p + 1] = lz[p];
    lz[2 * p] = lz[p];
    lz[2 * p + 1] = lz[p];
    lz[p] = 0;
}

void update(int p , int l , int r , int i , int j , int v){
    if(l > j || r < i)
        return;
    if(l >= i && r <= j){
        st[p] = v;
        lz[p] = v;
        return;
    }

    propagate(p);

    int mid = (l + r) >> 1;
    update(p * 2 , l , mid , i , j , v);
    update(p * 2 + 1 , mid + 1 , r , i , j , v);
}

int query(int p , int l , int r , int pos){
    if(l > pos || r < pos)
        return -1;
    if(l == r)
        return st[p];

    propagate(p);

    int mid = (l + r) >> 1;
    int p1 = query(p * 2 , l , mid , pos);
    int p2 = query(p * 2 + 1 , mid + 1 , r , pos);
    if(p1 == -1)return p2;
    return p1;
}


int memo[N][2];

int solve(int indx , int t){
    if(indx == 0)
        return 0;
    int &ret = memo[indx][t];
    if(~ret)
        return ret;

    ret = inf;
    ret = min(ret , cost[indx][t][0] + solve(nxt[indx][t] , 0));
    ret = min(ret , cost[indx][t][1] + solve(nxt[indx][t] , 1));
    return ret;
}


int main(){
    scanf("%d %d" , &n , &s);
    s += SHIFT;
    vector<pair<int , int> > v(n + 1);
    for(int i = 1 ; i <= n ; ++i)
        scanf("%d %d" , &v[i].first , &v[i].second);


    for(int i = 1 ; i <= n ; ++i){
        int l = v[i].first += SHIFT , r = v[i].second += SHIFT;
        int nxt0 = query(1 , 0 , M - 1 , l) , nxt1 = query(1 , 0 , M - 1 , r);
        if(nxt0 == 0){
            cost[i][0][0] = cost[i][0][1] = abs(l - (SHIFT));
        }
        else{
            cost[i][0][0] = abs(l - v[nxt0].first);
            cost[i][0][1] = abs(l - v[nxt0].second);
        }
        if(nxt1 == 0){
            cost[i][1][0] = cost[i][1][1] = abs(r - (SHIFT));
        }
        else{
            cost[i][1][0] = abs(r - v[nxt1].first);
            cost[i][1][1] = abs(r - v[nxt1].second);
        }
        nxt[i][0] = nxt0 , nxt[i][1] = nxt1;
        update(1 , 0 , M - 1 , l , r , i);
    }


    memset(memo , -1 , sizeof memo);

    printf("%d\n" , min(abs(s - v[n].first) + solve(n , 0) , abs(s - v[n].second) + solve(n , 1)));

}
