
struct trie{
    vector<vector<int> > v;

    trie () {
        v.emplace_back(vector<int>(2 , -1));
    }

    void insert(int x) {
        int cur = 0;
        for (int i = M ;i >= 0 ;i--) {
            bool bit = x & (1 << i);
            if (v[cur][bit] == -1) {
                v[cur][bit] = v.size();
                v.emplace_back(vector<int>(2 , -1));
            }
            cur = v[cur][bit];
        }
    }

    int query(int x) {
        int cur = 0 , ret = 0;
        for (int i = M ;i >= 0;i--) {
            bool bit = x & (1 << i);
            if (~v[cur][bit])
                cur = v[cur][bit];
            else {
                cur = v[cur][!bit];
                ret |= 1 << i;
            }
        }
        return ret;
    }
};
