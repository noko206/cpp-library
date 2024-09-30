template <class T> struct ZobristHash {
   public:
    ZobristHash(vector<T> a) : n(a.size()) {
        // ハッシュ割り当て
        static unordered_map<T, long long> mp;
        for (int i = 0; i < n; ++i) {
            if (mp.find(a[i]) == mp.end()) {
                mp[a[i]] = get_rand_range(1, mod - 1);
            }
        }
        // 累積和
        tot.resize(n + 1);
        tot[0] = 0;
        for (int i = 0; i < n; ++i) {
            tot[i + 1] = (tot[i] + mp[a[i]]) % mod;
        }
    }

    // [l, r)
    long long hash(int l, int r) {
        assert(0 <= l && l <= r && r <= n);
        return (tot[r] - tot[l] + mod) % mod;
    }

   private:
    // クソでか素数
    static const long long mod = (1LL << 61) - 1;
    int n;
    vector<long long> tot;

    long long get_rand_range(long long min_val, long long max_val) {
        static mt19937_64 mt64(0);
        uniform_int_distribution<uint64_t> get_rand_uni_int(min_val, max_val);
        return get_rand_uni_int(mt64);
    }
};
