/*
we need to check there is a solution at least
so using brute force(backtracing) we have to check all possible combinations of the shape
if there is a solution in one of them then output "yes"
otherwise output "no"
total complexity O(7! * 6 * 6)
*/
#include <bits/stdc++.h>
#define pb push_back
#define all(v) (v).begin() , (v).end()
#define popcnt(x) __builtin_popcount(x)
#define inf 0x3f3f3f3f
#define watch(x) cout << (#x) << " is " << (x) << endl
#define F first
#define S second

using namespace std;
typedef long long  ll;
const int N = 7;

vector<int> A[N];
bool v[N] , found = false;
vector<int> shape;

void solve(int indx){
    if(indx == N){
        vector<int> sides;
        for(int i = 0 ; i < 6 ; ++i){
            int x = A[shape[0]][i];
            for(int j = 0 ; j < 6 ; ++j){
                if(A[shape[i + 1]][j] == x){
                    sides.pb(A[shape[i + 1]][(j + 1) % 6]);
                    sides.pb(A[shape[i + 1]][(j - 1 + 6) % 6]);
                    break;
                }
            }
        }
        bool con = true;
        for(int i = 1 ; i < (int)sides.size() ; i += 2){
            if(sides[i] != sides[(i + 1) % (int)sides.size()]){
                con = false;
            }
        }
        found |= con;
        return;
    }

    for(int i = 0 ; i < N ; ++i){
        if(!v[i]){
            shape.pb(i);
            v[i] = true;
            solve(indx + 1);
            v[i] = false;
            shape.pop_back();
        }
    }
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r" , stdin);
#endif
    int tmp;
    while(cin >> tmp){
        found = false;
        for(int i = 0 ; i < N ; ++i)
            A[i].clear();
        A[0].pb(tmp);
        for(int i = 1 ; i < 6 ; ++i){
            cin >> tmp;
            A[0].pb(tmp);
        }

        for(int i = 1 ; i < N ; ++i){
            for(int j = 0 ; j < 6 ; ++j){
                cin >> tmp;
                A[i].pb(tmp);
            }
        }
        // numbers in clockwise labeling
        solve(0);
        cout << (found ? "YES\n" : "NO\n");
    }
}
