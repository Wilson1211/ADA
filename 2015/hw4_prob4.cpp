#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 50010;
const int M = 100010;

struct DisjointSet {
    int par[N], rank[N];
    void init(int n) {
        for (int i = 1; i <= n; i++) {
            par[i] = i;
            rank[i] = 0;
        }
    }
    int f(int x) {
        return x == par[x] ? x : par[x] = f(par[x]);
    }
    void u(int a, int b) {
        a = f(a);
        b = f(b);
        if (a == b) return;
        if (rank[a] > rank[b]) swap(a, b);
        if (rank[a] == rank[b]) rank[b]++;
        par[a] = b;
    }
} uf;

struct Edge {
    int a, b, c;
} es[M];

bool operator <(const Edge &a, const Edge &b) {
    return a.c < b.c;
}

int n, m;
vector<int> mst_eids;
long MST(int ban) {
    uf.init(n);
    long ans = 0;
    int cnt = 0;
    for (int i = 0; i < m && cnt < n - 1; i++) {
        if (i == ban) continue;
        if (uf.f(es[i].a) == uf.f(es[i].b)) continue;
        if (ban == -1) mst_eids.push_back(i);
        cnt++;
        ans += es[i].c;
        uf.u(es[i].a, es[i].b);
    }
    if (cnt < n - 1) return 1e18;
    return ans;
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &m);
        for (int i = 0; i < m; i++) {
            scanf("%d%d%d", &es[i].a, &es[i].b, &es[i].c);
        }
        sort(es, es + m);
        mst_eids.clear();
        auto mst = MST(-1);
        int ans_cnt = 0;
        long ans_sum = 0;
        for (int i : mst_eids) {
            auto c = MST(i);
            if (c > mst) {
                ans_cnt++;
                ans_sum += es[i].c;
            }
        }
        printf("%d %ld\n", ans_cnt, ans_sum);
    }
    return 0;
}
