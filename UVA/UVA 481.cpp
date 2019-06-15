#include <bits/stdc++.h>
#define pb push_back
#define all(v) (v).begin() , (v).end()
#define popcnt(x) __builtin_popcount(x)
#define inf 0x3f3f3f3f
#define watch(x) cout << (#x) << " is " << (x) << endl
#define rand() (rand() << 15 | rand())
using namespace std;

vector<int> LIS(vector<int> &a){
    int n = (int)a.size();
    vector<int> p(n , -1) , d(n , -1);
    vector<int> lis , lis_indexes;
    for(int i = 0 ; i < n ; ++i){
        int j = lower_bound(lis.begin() , lis.end() , a[i]) - lis.begin();
        if(j == (int)lis.size())lis.push_back(a[i]) , lis_indexes.pb(i);
        else lis[j] = a[i] , lis_indexes[j] = i;

        d[i] = j + 1;
        p[i] = (j ? lis_indexes[j - 1] : -1);
    }
    int lis_sz = *max_element(d.begin() , d.end()) , lst = -1;
    for(int i = 0 ; i < n ; ++i){
        if(d[i] == lis_sz){
            lst = i;
        }
    }
    vector<int> ret;
    while(lst != -1)
        ret.push_back(a[lst]) , lst = p[lst];
    reverse(ret.begin() , ret.end());
    return ret;
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt" , "r" , stdin);
#endif
    ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);
    int x;
    vector<int> a;
    while(cin >> x)
        a.pb(x);

    vector<int> lis = LIS(a);
    cout << (int)lis.size() << endl;
    cout << '-' << endl;
    for(int x : lis)
        cout << x << endl;
}
