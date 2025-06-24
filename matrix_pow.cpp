template <class T>
vector<vector<T>> matrix_pow(vector<vector<T>> a, long long n) {
    vector res(a.size(), vector<T>(a.size()));
    for (int i = 0; i < a.size(); i++) res[i][i] = 1;
    while (n > 0) {
        if (n & 1) res = matrix_mul(a, res);
        a = matrix_mul(a, a);
        n >>= 1;
    }
    return res;
}
