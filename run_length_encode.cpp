vector<pair<char, int>> run_length_encode(string s) {
    vector<pair<char, int>> ans;
    int i = 0, j = 0, n = s.length();
    while (i < n) {
        while (j < n && s[i] == s[j]) {
            ++j;
        }
        ans.push_back({s[i], j - i});
        i = j;
    }
    return ans;
}
