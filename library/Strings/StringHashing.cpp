const int P = 31 , MOD = 1e9 + 9; // Single Hashing parameters

void compute_hash(string const& s , vector<int> &preH) {
   int n = (int)s.size();
   preH.resize(n);
   long long hash_value = 0;
   long long p_pow = 1;
   for(int i = 0 ; i < n ; ++i){
      hash_value = (hash_value + (s[i] - 'a' + 1) * p_pow) % MOD;
      p_pow = (p_pow * P) % MOD;
      preH[i] = hash_value;
   }
}

int power(int b, int p) {
   if (p == 0) return 1;
   int res = power(b, p / 2);
   res = 1LL * res * res % MOD;
   if (p & 1) {
      res = 1LL * b * res % MOD;
   }
   return res;
}

int modInv(int x) {
   return power(x, MOD - 2);
}

int mul(int a , int b , int m){
   return (1LL * (a % m) * (b % m)) % m;
}

int add(int a , int b , int m){
   return (1LL * (a % m) + (b % m)) % m;
}

long long get_hash(int l , int r , vector<int> &preH){                     // returns hash value of substring using preH of string in O(log n) s.t. n is size of the string
   long long ret = (preH[r] - (l ? preH[l - 1] : 0) + MOD) % MOD;          // can be negative so we add MOD
   return mul(ret , modInv(power(P , l)) , MOD);                           // divide it by p^l
}