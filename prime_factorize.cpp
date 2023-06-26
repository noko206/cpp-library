template <class T> vector<pair<T, int>> prime_factorize(T n) {
    vector<pair<T, int>> ans;
    for (T i = 2; i * i <= n; ++i) {
        if (n % i != 0) continue;
        T e = 0;
        while (n % i == 0) {
            ++e;
            n /= i;
        }
        res.push_back({i, e});
    }
    if (n != 1) res.push_back({n, 1});
    return res;
}
