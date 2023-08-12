struct Doubling {
   public:
    Doubling(int n) : n(n), dp(61, vector<int>(n)) {
        for (int i = 0; i < n; ++i) {
            dp[0][i] = i;
        }
    };

    Doubling(const vector<int> &a)
        : n(a.size()), dp(61, vector<int>(a.size())) {
        dp[0] = a;
    };

    // 0-indexed
    void add_edge(int v, int u) { dp[0][v] = u; }

    void build() {
        for (int i = 0; i < 60; ++i) {
            for (int j = 0; j < n; ++j) {
                dp[i + 1][j] = dp[i][dp[i][j]];
            }
        }
    }

    // 0-indexed
    int query(int x, ll y) {
        int ans = x;
        for (int i = 0; i < 61; ++i) {
            if (y & (1LL << i)) {
                ans = dp[i][ans];
            }
        }
        return ans;
    }

   private:
    int n;
    vector<vector<int>> dp;
};
