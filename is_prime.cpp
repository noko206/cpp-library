template <class T> bool is_prime(T n) {
    if (n == 0 || n == 1) return false;
    for (T i = 2; i * i <= n; ++i) {
        if (n % i == 0) return false;
    }
    return true;
}
