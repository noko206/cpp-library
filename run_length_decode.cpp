string run_length_decode(const vector<pair<char, int>> &p) {
    string ans = "";
    for (auto [c, n] : p) {
        for (int i = 0; i < n; ++i) {
            ans += c;
        }
    }
    return ans;
}
