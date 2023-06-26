template <typename T> vector<T> decompress(const vector<T> &a) {
    auto ans = a;
    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());
    return ans;
}
