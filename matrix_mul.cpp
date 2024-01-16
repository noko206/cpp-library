template <class T> vector<vector<T>> matrix_mul(const vector<vector<T>> &a,
                                                const vector<vector<T>> &b) {
    vector<vector<T>> res(a.size(), vector<T>(b[0].size()));
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < b[0].size(); j++) {
            for (int k = 0; k < b.size(); k++) {
                res[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    return res;
}
