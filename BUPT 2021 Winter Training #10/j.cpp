//最大流+二分
#include <bits/stdc++.h>

using namespace std;
#define endl "\n"
#define ll long long
//const int inf=0x7fffffff;
const int inf = 0x3f3f3f3f;
const int maxm = 21111;
const int maxn = 5001;
int node, src, dest, edge;
int ver[maxm], flow[maxm], nxt[maxm];
int head[maxn], work[maxn], dis[maxn], q[maxn];

void init(int _node, int _src, int _dest) {
    node = _node, src = _src, dest = _dest;
    for (int i = 0; i < node; ++i)head[i] = -1;
    edge = 0;
}

void add_edge(int u, int v, int c) {
    ver[edge] = v, flow[edge] = c, nxt[edge] = head[u], head[u] = edge++;
    ver[edge] = u, flow[edge] = 0, nxt[edge] = head[v], head[v] = edge++;
}

bool Dinic_bfs() {
    int i, u, v, l, r = 0;
    for (i = 0; i < node; ++i)dis[i] = -1;
    dis[q[r++] = src] = 0;
    for (l = 0; l < r; ++l)
        for (i = head[u = q[l]]; i >= 0; i = nxt[i])
            if (flow[i] && dis[v = ver[i]] < 0) {
                dis[q[r++] = v] = dis[u] + 1;
                if (v == dest)return 1;
            }
    return 0;
}

int Dinic_dfs(int u, int exp) {
    if (u == dest)return exp;
    for (int &i = work[u], v, tmp; i >= 0; i = nxt[i])
        if (flow[i] && dis[v = ver[i]] == dis[u] + 1 && (tmp = Dinic_dfs(v, min(exp, flow[i]))) > 0) {
            flow[i] -= tmp;
            flow[i ^ 1] += tmp;
            return tmp;
        }
    return 0;
}

int Dinic_flow() {
    int i, ret = 0, delta;
    while (Dinic_bfs()) {
        for (i = 0; i < node; ++i)work[i] = head[i];
        while (delta = Dinic_dfs(src, inf))ret += delta;
    }
    return ret;
}

pair<int, int> ps[maxm];
int n, m;
int in[maxn], out[maxn];

bool check(int x) {
    int exp = 0;
    memset(in, 0, sizeof(in));
    memset(out, 0, sizeof(out));
    init(n + 2, 0, n + 1);
    for (int i = 0; i < m; ++i) {
        int u = ps[i].first, v = ps[i].second;
        out[u]++;
        in[v]++;
        add_edge(u, v, 1);
    }
    for (int i = 1; i <= n; ++i) {
        if (out[i] > x) {
            add_edge(0, i, out[i] - x);
            exp += out[i] - x;
        }
        if (out[i] < x) {
            add_edge(i, n + 1, x - out[i]);
        }
    }
    int f = Dinic_flow();
    return exp == f;
}

void printpath() {
    for (int i = 1; i <= n; i++) {
        for (int e = head[i]; e != -1; e = nxt[e]) {
            if (e & 1) continue;
            int v = ver[e];
            if (v < 1 || v > n || v < i) continue;
            if (flow[e]) {
                cout << i << " " << v << endl;
            } else {
                cout << v << " " << i << endl;
            }
        }
    }
}

void solve() {
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        if (a > b) swap(a, b);
        ps[i] = make_pair(a, b);
    }
    int l = 0, r = n;
    while (l < r) {
        int mid = (l + r) / 2;
        if (check(mid)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    if (check(l)) {
        cout << l << endl;
    } else {
        check(r);
        cout << r << endl;
    }
    printpath();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int _t;
    _t = 1;
    while (_t--) {
        solve();
    }
    return 0;
}