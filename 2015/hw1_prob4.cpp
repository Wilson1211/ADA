#include <cstdio>
const int N = 2e5 + 10;

int x[N];
long c, e, p, pow_tbl[2 * N];

long pow_mod(long a, long b) {
    long s = 1;
    while (b) {
        if (b & 1) s = s * a % p;
        b >>= 1;
        a = a * a % p;
    }
    return s;
}

bool cmp(int i, int j) {
    return c * (i - j + p) % p * pow_tbl[i + j] % p > p / 2;
}

void merge_sort(int l, int r) {
    static int _x[N];
    if (l == r) return;
    int m = (l + r) / 2;
    merge_sort(l, m);
    merge_sort(m + 1, r);
    for (int i = l; i <= r; i++) _x[i] = x[i];
    for (int i = l, j = l, k = m + 1; i <= r; i++) {
        if (j <= m && (k > r || cmp(_x[j], _x[k]))) x[i] = _x[j++];
        else x[i] = _x[k++];
    }
}

int main() {
    int t, n;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%ld%ld%ld", &n, &c, &e, &p);
        for (int i = 1; i <= n + n; i++) pow_tbl[i] = pow_mod(i, e);
        for (int i = 1; i <= n; i++) x[i] = i;
        merge_sort(1, n);
        for (int i = 1; i <= n; i++) printf("%d%c", x[i], " \n"[i == n]);
    }
    return 0;
}
