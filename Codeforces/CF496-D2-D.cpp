#include <bits/stdc++.h>
#define pb push_back
#define all(v) (v).begin() , (v).end()
#define popcnt(x) __builtin_popcount(x)
#define inf 0x3f3f3f3f
#define watch(x) cout << (#x) << " is " << (x) << endl
#define rand() (rand() << 15 | rand())
using namespace std;
typedef long long  ll;
int n;
vector<int> a , one , two;

int check(int t){
    int i = -1 , s1 = 0 , s2 = 0 , lst = -1;
    while(i < n - 1){
        int indx1 = lower_bound(all(one) , (~i ? one[i] + t : t)) - one.begin();
        int indx2 = lower_bound(all(two) , (~i ? two[i] + t : t)) - two.begin();
//        cout << indx1 << ' ' << indx2 << endl;
        if(indx1 < indx2)s1++ , lst = 1;
        else s2++ , lst = 2;
        i = min(indx1 , indx2);
    }
    if(i != n - 1 || s1 == s2)return -1;
    if(s1 > s2 && lst == 1)return s1;
    else if(s2 > s1 && lst == 2)return s2;
    else return -1;
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt" , "r" , stdin);
#endif
    ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);
    cin >> n;
    a.resize(n);
    for(int &x : a)
        cin >> x;

    one.resize(n , 0);
    two.resize(n , 0);
    one[0] += a[0] == 1;
    two[0] += a[0] == 2;
    for(int i = 1 ; i < n ; ++i){
        one[i] = one[i - 1] + (a[i] == 1);
        two[i] = two[i - 1] + (a[i] == 2);
    }

    vector<pair<int , int> > res;
    for(int t = 1 ; t <= n ; ++t){
        int s = check(t);
        if(s != -1)res.emplace_back(s , t);
    }

    sort(all(res));
    cout << (int)res.size() << "\n";
    for(auto e : res)
        cout << e.first << ' ' << e.second << "\n";
}
