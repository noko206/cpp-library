template <class T> int LIS(const vector<T> &a, bool is_strong) {
    int n = (int)a.size();
    vector<long long> dp(n, 1001001001001001001);
    for (int i = 0; i < n; ++i) {
        if (is_strong)
            // 狭義単調増加
            *lower_bound(dp.begin(), dp.end(), a[i]) = a[i];
        else
            // 広義単調増加
            *upper_bound(dp.begin(), dp.end(), a[i]) = a[i];
    }
    return lower_bound(dp.begin(), dp.end(), 1001001001001001001) - dp.begin();
}
