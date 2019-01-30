/*
    all we want to know for each element in the array what the maximum sub-array that can be formed
    such that that element will be the minimum in it
    if we have an element has maximum sub-array size SZ satisfy the condition above
    then it can be a minimum in sub-arrays with size [1:SZ]
*/
#include <bits/stdc++.h>

#define pb push_back
#define all(v) (v).begin() , (v).end()
#define popcnt(x) __builtin_popcount(x)
#define inf 0x3f3f3f3f
#define watch(x) cout << (#x) << " is " << (x) << endl

using namespace std;
typedef long long  ll;

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt" , "r" , stdin);
#endif
    ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for(int &x : a)
        cin >> x;

    vector<int> smaller_left(n , 0) , smaller_right(n , n - 1);

    priority_queue<pair<int , int> > pq;
    for(int i = 0 ; i < n ; ++i){
        while(!pq.empty() && pq.top().first >= a[i])pq.pop();
        if(!pq.empty())
            smaller_left[i] = pq.top().second + 1;
        pq.push({a[i] , i});
    }

    vector<int> res(n + 1);
    vector<pair<int , int> > data;
    while(!pq.empty())pq.pop();
    for(int i = n - 1 ; i >= 0 ; --i){
        while(!pq.empty() && pq.top().first >= a[i])pq.pop();
        if(!pq.empty())
            smaller_right[i] = pq.top().second - 1;
        int len = smaller_right[i] - smaller_left[i] + 1;
        res[len] = max(res[len] , a[i]);
        pq.push({a[i] , i});
    }

    for(int i = n - 1 ; i > 0 ; --i)
        res[i] = max(res[i] , res[i + 1]);

    for(int i = 1 ; i <= n ; ++i)
        cout << res[i] << ' ';
    cout << '\n';

}
