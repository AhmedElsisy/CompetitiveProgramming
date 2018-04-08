//UVA 1261
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

string str;
set<string> s;

bool solve(string s1){
    if(s1.empty())return 1;
    if(s.count(s1))
        return 0;
    s.insert(s1);

    bool con = false;

    for(int i = 0;i < (int)s1.size();++i){
        int j = i + 1 , cnt = 1;
        while(j < (int)s1.size() && s1[j] == s1[i]){
            cnt++;
            j++;
        }
        if(cnt <= 1)continue;
        string tmp = s1.substr(0 , i) + s1.substr(j);
        //tmp.erase(i , cnt);
        con |= solve(tmp);
        i = j - 1;
    }

    return con;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    int T;

    scanf("%d" , &T);

    while(T--){
        cin >> str;
        s.clear();

        if(solve(str))
            puts("1");
        else
            puts("0");
    }


}
