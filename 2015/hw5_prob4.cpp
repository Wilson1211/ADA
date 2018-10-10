#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 10010;
int rd[N], t, n, m, x1[N], x2[N], tx[N], u1[N], u2[N], v1[N], v2[N];
vector<int> e1[N], e2[N];

void init(vector<int> e[], int x[]) {
    for (int i = 1; i <= n; i++) e[i].clear();
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        e[a].push_back(b);
        if (a != b) e[b].push_back(a);
    }
    for (int i = 1; i <= n; i++) x[i] = rd[e[i].size()];
}

void step(vector<int> e[], int x[]) {
    for (int i = 1; i <= n; i++) {
        tx[i] = x[i];
        for (int j : e[i]) tx[i] += x[j];
    }
    for (int i = 1; i <= n; i++) x[i] = tx[i];
}

vector<pair<int, int>> magic(vector<int> e[], int x[], int u[], int v[]) {
    auto sort_by_x = [&](vector<int> &y) {
        sort(y.begin(), y.end(), [&](int a, int b) { return x[a] < x[b]; });
    };
    vector<int> ord, vis(n + 1);
    for (int i = 1; i <= n; i++) ord.push_back(i);
    sort_by_x(ord);
    int tn = 0;
    for (auto i : ord) if (!vis[i]++) {
        vector<int> q{i};
        for (size_t j = 0; j < q.size(); j++) {
            u[++tn] = q[j];
            vector<int> c;
            for (int k : e[q[j]]) if (!vis[k]++) c.push_back(k);
            sort_by_x(c);
            q.insert(q.end(), c.begin(), c.end());
        }
    }
    for (int i = 1; i <= n; i++) v[u[i]] = i;
    vector<pair<int, int>> r;
    for (int i = 1; i <= n; i++) for (int j : e[i]) r.emplace_back(v[i], v[j]);
    sort(r.begin(), r.end());
    return r;
}

int main() {
    for (int i = 0; i < N; i++) rd[i] = rand();
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &m);
        init(e1, x1);
        init(e2, x2);
        while (magic(e1, x1, u1, v1) != magic(e2, x2, u2, v2)) {
            step(e1, x1);
            step(e2, x2);
        }
        for (int i = 1; i <= n; i++) printf("%d%c", u2[v1[i]], " \n"[i == n]);
    }
    return 0;
}
