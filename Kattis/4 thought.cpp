#include <bits/stdc++.h>
#define pb push_back
#define all(v) (v).begin() , (v).end()
#define popcnt(x) __builtin_popcount(x)
#define inf 0x3f3f3f3f
#define watch(x) cout << (#x) << " is " << (x) << endl
#define rand() (rand() << 15 | rand())

using namespace std;
typedef long long  ll;
typedef long double  ld;

vector<int> v = {4 , 4 , 4 , 4};
vector<char> s;
string res = "";
map<char , int> precedence;
int x;

void evaluate(){
    vector<int> tmpV = v;
    vector<char> tmpS = s;
    string ex = "";
    for(int i = 0 ; i < 4 ; ++i){
        if(i != 3){
            ex += "4 ";
            ex.pb(tmpS[i]);
            ex.pb(' ');
        }
        else ex.pb('4');
    }

    while((int)tmpV.size() > 1){
        int mx = -1 , indx = -1;
        for(int i = 0 ; i + 1 < (int)tmpV.size() ; ++i){
            char c = tmpS[i];
            if(precedence[c] > mx){
                mx = precedence[c];
                indx = i;
            }
        }

        int new_value = -1;
        if(tmpS[indx] == '*'){
            new_value = tmpV[indx] * tmpV[indx + 1];
        }
        else if(tmpS[indx] == '/'){
            if(tmpV[indx + 1] == 0)return;
            new_value = tmpV[indx] / tmpV[indx + 1];
        }
        else if(tmpS[indx] == '-'){
            new_value = tmpV[indx] - tmpV[indx + 1];
        }
        else{
            new_value = tmpV[indx] + tmpV[indx + 1];
        }
        tmpS.erase(tmpS.begin() + indx);
        tmpV.erase(tmpV.begin() + indx + 1);
        tmpV[indx] = new_value;
    }
    if(tmpV[0] == x){
        res = ex;
    }
}
void solve(int indx){
    if(indx == 3){
        evaluate();
        return;
    }

    s.pb('/');
    solve(indx + 1);
    s.pop_back();

    s.pb('+');
    solve(indx + 1);
    s.pop_back();

    s.pb('-');
    solve(indx + 1);
    s.pop_back();

    s.pb('*');
    solve(indx + 1);
    s.pop_back();
    return;
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt" , "r" , stdin);
#endif
    ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);
    precedence['/'] = 4;
    precedence['*'] = 3;
    precedence['+'] = 2;
    precedence['-'] = 2;
    int t;
    cin >> t;
    while(t--){
        res = "";
        cin >> x;
        solve(0);
        if(res.empty())
            cout << "no solution\n";
        else cout << res << " = " << x << "\n";
    }
}
