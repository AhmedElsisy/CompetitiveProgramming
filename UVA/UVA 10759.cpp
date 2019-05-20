#include <bits/stdc++.h>
#define pb push_back
#define all(v) (v).begin() , (v).end()
#define popcnt(x) __builtin_popcount(x)
#define inf 0x3f3f3f3f
#define watch(x) cout << (#x) << " is " << (x) << endl
#define rand() (rand() << 15 | rand())
using namespace std;
typedef long long  ll;

// for probability & expectation problems
struct Fraction{
    long long up , down;
    Fraction(){up = down = 0;}
    Fraction(long long u , long long d){
        up = u , down = d;
    }
    void simplify(){
        long long gcd = __gcd(up , down);
        if(gcd != 0)
            up /= gcd , down /= gcd;
    }
    Fraction operator *(const Fraction &b) const{
        Fraction c = Fraction(up * b.up , down * b.down);
        c.simplify();
        return c;
    }
    Fraction operator +(const Fraction &b) const{
        if(!up)return b;
        long long lcm = down * (b.down / __gcd(down , b.down));
        return Fraction(up * (lcm / down) + b.up * (lcm / b.down) , lcm);
    }
    void print(){
        if(!up)
            cout << "0\n";
        else if(up == down)
            cout << "1\n";
        else
            cout << up << "/" << down << "\n";
    }
};

const int N = 25 , M = 24 * 6 + 1;
Fraction memo[N][M];
int vis[N][M] , vid = 1;
int n , x;

Fraction solve(int indx , int sum){
    if(indx == n)
        return (sum >= x ? Fraction(1 , 1) : Fraction(0 , 0));

    Fraction &ret = memo[indx][sum];
    if(vis[indx][sum] == vid)
        return ret;
    vis[indx][sum] = vid;

    ret = {0 , 0};
    Fraction p = {1 , 6};
    for(int i = 1 ; i <= 6 ; ++i){
        Fraction add = p * solve(indx + 1 , sum + i);
        ret = ret + add;
    }
    return ret;
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt" , "r" , stdin);
#endif
    ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);
    while(cin >> n >> x){
        if(!n && !x)
            return 0;
        Fraction ans = solve(0 , 0);
        ans.simplify();
        ans.print();
        ++vid;
    }
}
