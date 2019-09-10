// written by wolf
struct BIT {
    vector<int> tree;           // check long long here
    BIT(int n) : tree(n + 2){}

    void upd(int p , int v) {
        for (int i = ++p ;i < tree.size() ; i += i & -i)
            tree[i] += v;
    }

    int get(int p) {
        int sum = 0;            // check long long here
        for (int i = ++p; i ; i -= i & -i)
            sum += tree[i];
        return sum;
    }

    int query(int l , int r) {
        return get(r) - get(l - 1);
    }

    int get_kth(int k) {
        int pos = 0 , s = 0;
        for (int i = 1 + log2(tree.size()) ;i >= 0 ;i--)
            if (pos + (1 << i) < tree.size() && s + tree[pos + (1 << i)] < k)
                s += tree[pos + (1 << i)] , pos += (1 << i);
        return pos;
    }

    int lower_bound(int v) {
        return get_kth(get(v - 1) + 1);
    }

    int upper_bound(int v) {
        return lower_bound(v + 1);
    }
};
