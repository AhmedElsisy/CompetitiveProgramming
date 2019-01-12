/*
    for each index j as B[j] you need to find A[i] s.t. total distance as minimum possible
    its easy to observe that for each B[j] , A[] represent a ternary function
    for example the optimal point is (x , y) so if we increase y or decrease y the total distance will increase
    so we fix B[j] and calculate the minimum distance then store it then output the pair that form the minimum
*/

#include <bits/stdc++.h>

#define pb push_back
#define all(v) (v).begin() , (v).end()
#define popcnt(x) __builtin_popcount(x)
#define inf 0x3f3f3f3f
#define watch(x) cout << (#x) << " is " << (x) << endl

using namespace std;
typedef long long  ll;
int n , m , a , b;
vector<int> A , B , l;

double getdist(int x1 , int y1 , int x2 , int y2){
    ll dx = (x1 - x2) , dy = (y1 - y2);
    return sqrt(dx * dx + dy * dy);
}

double gettotal(int indxA , int indxB){
    if(indxA < 0 || indxA >= n)
        return 1e18;
    return getdist(0 , 0 , a , A[indxA]) + getdist(a , A[indxA] , b , B[indxB]) + l[indxB];
}

int tr(int indx){
    int l = 0 , r = n - 1;
    while(l < r){
        int mid = (l + r) / 2;

        double c_0 = gettotal(mid - 1 , indx);
        double c_1 = gettotal(mid , indx);
        double c_2 = gettotal(mid + 1 , indx);

        if(c_1 <= c_0 && c_1 <= c_2)
            return mid;

        if(c_0 < c_2)r = mid - 1;
        else if(c_2 < c_0)l = mid + 1;
    }
    watch(1);
    return (gettotal(l , indx) < gettotal(r , indx) ? l : r);
}

pair<double , int> getmin(int indx){
    int ret = tr(indx);
    double cost = gettotal(ret , indx);
    return {cost , ret};
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);
    cin >> n >> m >> a >> b;
    A.resize(n) , B.resize(m) , l.resize(m);

    for(int &x : A)
        cin >> x;

    for(int &x : B)
        cin >> x;

    for(int &x : l)
        cin >> x;

    double mnCost = 1e9;
    int x1 = -1 , x2 = -1;
    for(int i = 0 ; i < m ; ++i){
        pair<double , int> s = getmin(i);
        if(s.first < mnCost){
            mnCost = s.first;
            x1 = s.second + 1;
            x2 = i + 1;
        }
    }

    cout << x1 << ' ' << x2 << '\n';
}
