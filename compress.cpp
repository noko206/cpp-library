template <typename T> map<int, T> compress(const vector<T> &a) {
    map<int, T> ans;
    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());
    for (int i = 0; i < (int)a.size(); ++i) {
        ans[a[i]] = i;
    }
    return ans;
}
