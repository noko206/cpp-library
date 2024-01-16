template <class T>
vector<vector<T>> matrix_pow(const vector<vector<T>> &a, long long n) {
    vector<vector<T>> res(a.size(), vector<ll>(a.size()));
    for (int i = 0; i < a.size(); i++) res[i][i] = 1;
    while (n > 0) {
        if (n & 1) res = mat_mul(a, res);
        a = mat_mul(a, a);
        n >>= 1;
    }
    return res;
}
