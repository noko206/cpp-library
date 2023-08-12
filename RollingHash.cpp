struct RollingHash {
   public:
    RollingHash(const string &s, int base = 100, int mod = 998244353)
        : base(base), mod(mod), hash(s.length()) {
        mint::set_mod(mod);
        build(s);
    }

    // [l, r)
    int query(int l, int r) {
        mint ans = hash[r] - (hash[l] * pow_mod(base, r - l, mod));
        return ans.val();
    }

   private:
    using mint = modint;
    int base;
    int mod;
    vector<mint> hash;

    void build(const string &s) {
        int n = s.length();
        hash[0] = 0;
        for (int i = 0; i < n; ++i) {
            hash[i + 1] = hash[i] * base + s[i];
        }
    }
};
