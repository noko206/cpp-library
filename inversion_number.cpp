template <class T> long long inversion_number(const vector<T> &a) {
    auto b = a;
    sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());
    fenwick_tree<long long> ft((int)b.size());
    long long ans = 0;
    int n = (int)a.size();
    for (int i = 0; i < n; ++i) {
        int rank = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
        ans += i - ft.sum(0, rank + 1);
        ft.add(rank, 1);
    }
    return ans;
}
