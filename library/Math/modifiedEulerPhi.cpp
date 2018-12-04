const int N = 1e7;
bitset<N> p;
int ans[N];

// call pre first
void pre(){
    iota(ans , ans + N , 0);
}
void modifiedEulerPhi(){
    p.set();
    p[0] = p[1] = 0;
    for(int i = 2 ; i < N ; ++i){
        if(p[i]){
            ans[i] -= ans[i] / i;
            for(int j = i * 2 ; j < N ; j += i)p[j] = 0 , ans[j] -= ans[j] / i;
        }
    }
}

