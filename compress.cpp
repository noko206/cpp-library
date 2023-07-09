template <typename T>
pair<unordered_map<T, int>, vector<T>> compress(const vector<T> &a) {
    auto decomp = a;
    sort(decomp.begin(), decomp.end());
    decomp.erase(unique(decomp.begin(), decomp.end()), decomp.end());
    unordered_map<T, int> comp;
    for (int i = 0; i < (int)decomp.size(); ++i) {
        comp[decomp[i]] = i;
    }
    return {comp, decomp};
}