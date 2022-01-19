#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
#define y1 y1234567890

#define fast_io ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define file_io(s) freopen((s)".in", "r", stdin); freopen((s)".out", "w", stdout)

const int N = 1e5;
const int M = N + 7;
const double EPS = 1e-10;

const int MOD = 1e9 + 7;
const ll INF = 2e13;

int a[M];
vector<pair<int, pii>> edges;

int sz[M], p[M];
ll mx[M], sum[M];

int getParent(int v) {
    return p[v] = (p[v] == v ? v : getParent(p[v]));
}

void merge(int v, int u, int w) {
    v = getParent(v);
    u = getParent(u);
    if (v == u)
        return;
    if (sz[v] < sz[u])
        swap(v, u);

    ll fromV = -INF, fromU = -INF;
    if (sum[v] <= mx[u]) {
        fromV = min(mx[u], 1LL * w) - sum[v];
    }
    if (sum[u] <= mx[v]) {
        fromU = min(mx[v], 1LL * w) - sum[u];
    }
    mx[v] = max(fromV, fromU);
    sum[v] += sum[u];

    p[u] = v;
    sz[v] += sz[u];
}

void solve() {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        p[i] = i;
        sz[i] = 1;
        mx[i] = INF;
        sum[i] = a[i];
    }
    for (int i = 1; i <= m; i++) {
        int v, u, w;
        scanf("%d %d %d", &v, &u, &w);
        edges.pb({w, {v, u}});
    }
    sort(all(edges));
    reverse(all(edges));

    for (auto &edge : edges) {
        merge(edge.se.fi, edge.se.se, edge.fi);
    }

    int v = getParent(1);
    if (sz[v] != n || mx[v] < 1) {
        printf("-1\n");
    } else {
        printf("%lld\n", mx[v]);
    }
}

int main() {
    int tt = 1;
    // scanf("%d", &tt);
    while (tt--) {
        solve();
    }
    return 0;
}