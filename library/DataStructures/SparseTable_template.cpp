template <typename T, class F = function<T(const T&, const T&)>>
class SparseTable {
public:
   int n;
   vector<vector<T>> sp;
   F func;
   SparseTable(const vector<T> &a , const F& f) : func(f) {
      n = static_cast<int>(a.size());
      int max_log = 32 - __builtin_clz(n);
      sp.resize(max_log);
      sp[0] = a;
      for (int j = 1; j < max_log; ++j) {
         sp[j].resize(n - (1 << j) + 1);
         for (int i = 0; i <= n - (1 << j); ++i) {
            sp[j][i] = func(sp[j - 1][i], sp[j - 1][i + (1 << (j - 1))]);
         }
      }
   }
   T get(int l , int r) const {
      int lg = 32 - __builtin_clz(r - l + 1) - 1;
      return func(sp[lg][l] , sp[lg][r - (1 << lg) + 1]);
   }
};


int main(){
    vector<int> a = {1 , 2 , 3, 4};
    SparseTable<int> sp(a , [&](int i , int j){return __gcd(i , j);});
    cout << sp.get(0 , 3) << "\n";
    cout << sp.get(2 , 3) << endl;
}
