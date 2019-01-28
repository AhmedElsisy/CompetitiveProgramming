/*
    ordered set is a c++ stl : policy based data structure
    let s be ordered set stores the unread messages
    and adj[x] be the messages of application x
    simply when query of type 2 is happened , iterate over unread messages x
    and query of type 3 , iterate over all messages it's index less than t
*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define pb push_back
#define all(v) (v).begin() , (v).end()
#define popcnt(x) __builtin_popcount(x)
#define inf 0x3f3f3f3f
#define watch(x) cout << (#x) << " is " << (x) << endl

using namespace __gnu_pbds;
using namespace std;
typedef long long  ll;

template<typename T>
using ordered_set =
tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int N = 3e5 + 4;
int n , q;
ordered_set<pair<int , int> > s;
set<int> adj[N];

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt" , "r" , stdin);
#endif
    cin >> n >> q;

    int cnt = 0 , message = 1;
    for(int i = 1 ; i <= q ; ++i){
        int type , t;
        cin >> type >> t;
        if(type == 1){
            s.insert({message , t});
            adj[t].insert(message);
            message++;
            cnt++;
        }
        else if(type == 2){
            for(int x : adj[t]){
                auto it = s.lower_bound({x , t});
                s.erase(it);
            }
            cnt -= adj[t].size();
            adj[t].clear();
        }
        else if(!s.empty()){
            auto it = s.begin();
            while((*it).first <= t){
                int x = (*it).second , ind = (*it).first;
                adj[x].erase(ind);
                s.erase(it);
                --cnt;
                if(s.empty())break;
                it = s.begin();
            }
        }

        cout << cnt << '\n';
    }
}
