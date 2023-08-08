template <typename T> T binomial(int n, int k) {
    if (k < 0 || n < k) return 0;
    static vector<T> fact;
    static vector<T> ifact;
    if ((int)fact.size() < n + 1) {
        int pos = (int)fact.size();
        fact.resize(n + 1);
        for (int i = pos; i <= n; ++i) {
            if (i > 0) {
                fact[i] = i * fact[i - 1];
            } else {
                fact[i] = 1;
            }
        }
    }
    int mx = max(k, n - k);
    if ((int)ifact.size() < mx + 1) {
        int pos = (int)ifact.size();
        ifact.resize(mx + 1);
        ifact[mx] = 1 / fact[mx];
        for (int i = mx - 1; i >= pos; --i) {
            ifact[i] = (i + 1) * ifact[i + 1];
        }
    }
    return fact[n] * ifact[k] * ifact[n - k];
}
