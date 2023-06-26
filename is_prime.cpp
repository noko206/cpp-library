template <class T> bool is_prime(T n) {
    for (T i = 2; i * i <= n; ++i) {
        if (n % i == 0) return true;
    }
    return false;
}
