/*
    just create two sets of pairs :
        1) set stores {length of continuous equal elements , indx of segment} , to get the next segment to be removed
        2) set stores {indx of segment , length of continuous equal elements} , to get track of the rest of segments
    every step you remove the next segment and check if the two neighbors(if exists) of the next segment has equal elements
    you should merge them in on segment with new length (their sum)
*/
#include <bits/stdc++.h>
#define pb push_back
#define all(v) (v).begin() , (v).end()
#define popcnt(x) __builtin_popcount(x)
#define inf 0x3f3f3f3f
#define watch(x) cout << (#x) << " is " << (x) << endl
#define rand() (rand() << 15 | rand())

using namespace std;
typedef long long  ll;
const int N = 2e5 + 4;

int belong[N];
set<pair<int , int> > pool , getNext;

void del(int f1 , int f2){
    getNext.erase(getNext.lower_bound({-f2 , f1}));
}

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


    int indx = 0;
    for(int i = 0 ; i < n ; ++i){
        int j = i;
        while(j < n && a[j] == a[i])++j;
        int cnt = j - i;
        belong[indx] = a[i];
        pool.insert({indx , cnt});
        getNext.insert({-cnt , indx++});
        i = j - 1;
    }

    int cnt = 0;
    while(!getNext.empty()){
        auto nxt = *getNext.begin();
        getNext.erase(getNext.begin());

        auto it1 = pool.lower_bound({nxt.second , -nxt.first});
        auto it2 = pool.lower_bound({nxt.second , -nxt.first});

        if(it1 != pool.begin() && ++it2 != pool.end()){
            --it1;
            if(belong[(*it1).first] == belong[(*it2).first]){
                int sum = (*it1).second + (*it2).second;
                int new_indx = (*it2).first;
                del((*it1).first , (*it1).second);
                pool.erase(it1);
                del((*it2).first , (*it2).second);
                pool.erase(it2);
                pool.insert({new_indx , sum});
                getNext.insert({-sum , new_indx});
            }
        }
        pool.erase(pool.lower_bound({nxt.second , -nxt.first}));
        ++cnt;
    }

    cout << cnt << "\n";
}
