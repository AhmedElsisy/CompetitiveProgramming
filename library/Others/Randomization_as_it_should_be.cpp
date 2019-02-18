#define rand() (rand() << 15 | rand())

int main(){
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

    vector<int> per;
    for(int i = 0 ; i < n ; ++i)per.pb(i);
    shuffle(all(per) , rng);
    // or
    set<int> s;
    s.insert(uniform_int_distribution<int>(1,n)(rng));
    // it generates [0,2^32 - 1] 32-bit unsigned

    vector<int> per2;
    for(int i = 0 ; i < n ; ++i)per2.pb(rand() % n);

    // (rand() << 15 | rand()) does generate [0,2^30] uniformly
}
