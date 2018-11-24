//UVA 10341
#include <bits/stdc++.h>

using namespace std;
#define pb push_back
#define all(v) (v).begin() , (v).end()
#define popcnt(x) __builtin_popcount(x)
#define popcntll(x) __builtin_popcountll(x)
#define inf 0x3f3f3f3f  //integers only
#define watch(x) cout << (#x) << " is " << (x) << endl
#define isOn(S, j) (S & (1 << j))
#define setBit(S, j) (S |= (1 << j))
#define clearBit(S, j) (S &= ~(1 << j))
#define endl '\n'

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef long long  ll;

const double pi = acos(-1);
int dx[] = {0 , 0 , 1 , -1 , 1 , 1 , -1 , -1};
int dy[] = {1 ,-1 , 0 , 0 , -1 , 1 ,  1 , -1};
const double EPS = 1e-9;

int p , q , r , s , t , u;

double solve(double x){
    double sq = x * x;
    return (p * exp(-1 * x)) + (q * sin(x)) + (r * cos(x)) +(s * tan(x)) + (t * sq) + u;
}

double bs(){
    double l = 0 , r = 1 , ans = -1;
    int cnt = 50;
    while(cnt--){
        double mid = (l + r) / 2.0;
        if(fabs(solve(mid) - 0) <= EPS){
            ans = mid;
            l = mid;
        }
        else if(solve(mid) > 0){
            l = mid;
        }
        else if(solve(mid) < 0){
            r = mid;
        }
    }
    return ans;
}


int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    while(scanf("%d %d %d %d %d %d" , &p , &q , &r , &s , &t , &u) != EOF){
        double x = bs();
        if(fabs(x - -1) <= EPS)
            puts("No solution");
        else
            printf("%.4f\n" , x);
    }
}
