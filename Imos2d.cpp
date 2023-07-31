template <class T> struct Imos2d {
   public:
    Imos2d(int h, int w) : h(h), w(w), data(h + 1, vector<T>(w + 1, 0)){};

    // [si, gi), [sj, gj)
    void add(int si, int sj, int gi, int gj, T x) {
        assert(0 <= si && si <= gi && gi <= h);
        assert(0 <= sj && sj <= gj && gj <= w);
        data[si][sj] += x;
        data[si][gj] -= x;
        data[gi][sj] -= x;
        data[gi][gj] += x;
    }

    void build() {
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                data[i + 1][j] += data[i][j];
            }
        }
        for (int j = 0; j < w; ++j) {
            for (int i = 0; i < h; ++i) {
                data[i][j + 1] += data[i][j];
            }
        }
    }

    T get(int i, int j) {
        assert(0 <= i && i < h);
        assert(0 <= j && j < w);
        return data[i][j];
    }

   private:
    int h, w;
    vector<vector<T>> data;
};
