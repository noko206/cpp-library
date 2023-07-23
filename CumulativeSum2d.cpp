template <class T> struct CumulativeSum2d {
   public:
    CumulativeSum2d(int h, int w)
        : h(h), w(w), data(h + 1, vector<T>(w + 1, 0)){};
    CumulativeSum2d(const vector<vector<T>> &v)
        : h((int)v.size()), w((int)v[0].size()) {
        data.resize(h + 1);
        data[0].resize(w + 1, 0);
        for (int i = 0; i < h; ++i) {
            data[i + 1].resize(w + 1, 0);
            for (int j = 0; j < w; ++j) {
                data[i + 1][j + 1] = v[i][j];
            }
        }
    };

    void add(int i, int j, T x) {
        assert(0 <= i && i < h);
        assert(0 <= j && j < w);
        data[i + 1][j + 1] += x;
    }

    void build() {
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                data[i + 1][j + 1] +=
                    data[i + 1][j] + data[i][j + 1] - data[i][j];
            }
        }
    }

    // [si, gi), [sj, gj)
    T sum(int si, int sj, int gi, int gj) {
        assert(0 <= si && si <= gi && gi <= h);
        assert(0 <= sj && sj <= gj && gj <= w);
        return data[gi][gj] - data[si][gj] - data[gi][sj] + data[si][sj];
    }

   private:
    int h, w;
    vector<vector<T>> data;
};
