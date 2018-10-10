#include <cstdio>
#include <cstring>

const int D = 20;

int n_digit, digit[D];
long dp[2][D][D][D][7];

long go(bool any, int pos, int c4, int c7, int m7) {
    if (pos == -1) return c4 < c7 && c7 >= 3 && m7 == 0;
    long &ret = dp[any][pos][c4][c7][m7];
    if (ret != -1) return ret;
    ret = 0;
    int ub = any ? 9 : digit[pos];
    for (int i = 0; i <= ub; i++) {
        int _c4 = c4 + (i == 4);
        int _c7 = c7 + (i == 7);
        int _m7 = (m7 * 10 + i) % 7;
        bool _any = any || (i < digit[pos]);
        ret += go(_any, pos - 1, _c4, _c7, _m7);
    }
    return ret;
}

long solve(long n) {
    for (n_digit = 0; n != 0; n /= 10) digit[n_digit++] = n % 10;
    memset(dp, -1, sizeof(dp));
    return go(0, n_digit - 1, 0, 0, 0);
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        long l, r;
        scanf("%ld%ld", &l, &r);
        printf("%ld\n", solve(r) - solve(l - 1));
    }
    return 0;
}
