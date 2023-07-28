template <class T, T (*merge)(T, T), T (*add_root)(T), T (*e)()>
struct Rerooting {
   public:
    Rerooting(int n) : n(n), to(n), dp_e(n), dp_v(n){};

    // 有向辺u->vを張る
    void add_edge(int u, int v) {
        assert(0 <= u && u < n);
        assert(0 <= v && v < n);
        to[u].push_back(v);
    }

    void build() {
        dfs();
        dfs_all();
    }

    // ある頂点のDP値
    T get_v(int idx) {
        assert(0 <= idx && idx < n);
        return dp_v[idx];
    }

    // ある頂点から辺で結ばれている各頂点を根とする部分木のDP値
    vector<T> get_e(int idx) {
        assert(0 <= idx && idx < n);
        return dp_e[idx];
    }

   private:
    int n;
    vector<T> dp_v;
    vector<vector<T>> dp_e;
    vector<vector<int>> to;

    // 木DP
    T dfs(int v = 0, int p = -1) {
        T dp_x = e();
        int deg = (int)to[v].size();
        dp_e[v] = vector<T>(deg, e());
        for (int i = 0; i < deg; ++i) {
            int u = to[v][i];
            if (u == p) continue;
            dp_e[v][i] = dfs(u, v);
            dp_x = merge(dp_x, dp_e[v][i]);
        }
        return add_root(dp_x);
    }

    // 残りの部分木に対応するDP値を計算
    void dfs_all(int v = 0, const T &dp_p = e(), int p = -1) {
        int deg = (int)to[v].size();
        for (int i = 0; i < deg; ++i) {
            if (to[v][i] == p) dp_e[v][i] = dp_p;
        }
        vector<T> dp_l(deg + 1, e()), dp_r(deg + 1, e());
        for (int i = 0; i < deg; ++i) {
            dp_l[i + 1] = merge(dp_l[i], dp_e[v][i]);
        }
        for (int i = deg - 1; i >= 0; --i) {
            dp_r[i] = merge(dp_r[i + 1], dp_e[v][i]);
        }
        dp_v[v] = add_root(dp_l[deg]);
        for (int i = 0; i < deg; ++i) {
            int u = to[v][i];
            if (u == p) continue;
            dfs_all(u, add_root(merge(dp_l[i], dp_r[i + 1])), v);
        }
    }
};
