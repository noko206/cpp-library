long long pow_mod(long long x, long long n, long long m) {
    if (n == 0) return 1;
    if (n == 1) return x % m;
    if (n % 2 == 1) return (x * pow_mod(x, n - 1, m)) % m;
    long long t = pow_mod(x, n / 2, m);
    return (t * t) % m;
}
