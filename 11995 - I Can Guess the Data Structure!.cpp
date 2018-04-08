//UVA 11995
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

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    int n;

    while(scanf("%d" , &n) != EOF){

        queue<int> q;
        stack<int> s;
        priority_queue<int> pq;

        bool isQUEUE , isSTACK , isPRIORITYQUEUE;
        isQUEUE = isSTACK = isPRIORITYQUEUE = true;

        int x , v;
        for(int i = 0 ; i < n ; ++i){

            scanf("%d %d" , &x , &v);
            if(x == 1){
                q.push(v);
                s.push(v);
                pq.push(v);
            }
            else{
                if(!q.empty()){
                    if(v != q.front())isQUEUE = false;
                    q.pop();
                }
                else isQUEUE = false;

                if(!s.empty()){
                    if(v != s.top())isSTACK = false;
                    s.pop();
                }
                else isSTACK = false;

                if(!pq.empty()){
                    if(v != pq.top())isPRIORITYQUEUE = false;
                    pq.pop();
                }
                else isPRIORITYQUEUE = false;
            }
        }

        int ans = isQUEUE + isSTACK + isPRIORITYQUEUE;
        if(ans >= 2){
            puts("not sure");
        }
        else if(ans == 1){
            if(isQUEUE)puts("queue");
            else if(isPRIORITYQUEUE)puts("priority queue");
            else puts("stack");
        }
        else puts("impossible");
    }
}
