vector<int> enum_primes(int n) {
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = false;
    is_prime[1] = false;
    for (int i = 2; i <= n; ++i) {
        if (!is_prime[i]) continue;
        for (int j = i * 2; j <= n; j += i) {
            is_prime[i] = false;
        }
    }
    vector<int> ans;
    REP(i, n + 1) {
        if (is_prime[i]) ans.push_back(i);
    }
    return ans;
}
