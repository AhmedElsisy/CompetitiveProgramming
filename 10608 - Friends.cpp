#include <bits/stdc++.h>

using namespace std;

int dx[] = {0 , 0 , 1 , 1 , 1 , -1 , -1 , -1};
int dy[] = {1 , -1 , 1 , -1 , 0 , 0 , 1 , -1};

struct DS {
    vector<int> vec;
    vector<int> sizeset;
    DS(int n){
        vec.resize(n+1);
        sizeset.resize(n+1);
        for(int i=1;i<=n;++i){
            vec[i] = i;
        }
        for(int i=1;i<=n;++i){
            sizeset[i] = 1;
        }
    }
    int findset(int n){
        if(vec[n] == n){
            return n;
        }
        return vec[n] = findset(vec[n]);
    }
    void unionset(int i,int j){
        int x = findset(i);
        int y = findset(j);
        if (x != y){
            if(sizeset[y]>sizeset[x])
                swap(x,y);
            vec[y] = x;
            sizeset[x] += sizeset[y];
        }
    }
    int sizeofset(int i){
        return sizeset[i];
    }
};

int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        int n,m;
        scanf("%d %d",&n,&m);
        DS d(n);
        for(int i=0;i<m;++i){
            int a,b;
            scanf("%d %d",&a,&b);
            d.unionset(a,b);
        }
        int mx = -1;
        for(int i=1;i<=n;++i){
            mx = max(mx,d.sizeofset(i));
        }
        printf("%d\n",mx);
    }
    return 0;
}
