#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,fma,tune=native")
#define vec vector
#define str(x) to_string(x)
#define len(x) int(x.size())
#define all(x) begin(x), end(x)
#define rep(x, from, to) for(int x = from; x < to; x++)
#define repd(x, from, to) for(int x = from - 1; x >= to; x--)
#define lbound(arr, x) distance(begin(arr), lower_bound(all(arr), x))
#define ubound(arr, x) distance(begin(arr), upper_bound(all(arr), x))
#ifndef ONLINE_JUDGE
#define dbg(x) cout << #x << " =\n" << x << "\n";
#else
#define dbg(x) 0
#endif
using namespace std;
using ll = long long;
using ull = unsigned long long;
using uint = unsigned int;
using uchar = unsigned char;
using pii = pair<int, int>;
using pill = pair<int, ll>;
using plli = pair<ll, int>;
using vi = vec<int>;
using vpii = vec<pii>;
using vplli = vec<plli>;
using vpill = vec<pill>;
using vll = vec<ll>;
using vull = vec<ull>;
using vchar = vec<char>;
using vuchar = vec<uchar>;
using vstr = vec<string>;
using vuint = vec<uint>;
using graph = vec<vi>;
using wgraph = vec<vpii>;

template<class A>
ostream& operator<<(ostream& o, const vector<A> a) {
    for (auto v : a)
        o << v << " ";

    return o << "\n";
}

template<class A>
ostream& operator<<(ostream& o, const set<A> a) {
    for (auto v : a)
        o << v << " ";

    return o << "\n";
}

template<class A>
ostream& operator<<(ostream &o, const multiset<A> a) {
    for (auto v : a)
        o << v << " ";

    return o << "\n";
}

template<class A, class K>
ostream& operator<<(ostream &o, const map<A, K> a) {
    for (auto [k, v] : a)
        o << k << ": " << v << "\n";

    return o;
}

template<class A, class B>
ostream& operator<<(ostream &o, const pair<A, B> p) {
    return o << p.first << " " << p.second << "\n";
}

vector<int> order;
vector<vector<int>> g;

void add(int u, int v) {
    g[u].push_back(v);
}

int get_order(int u) {
    if (order[u] != -1) return order[u];
    if (g[u].empty()) return (order[u] = 0);
    order[u] = get_order(g[u].back());
    for (int i = len(g[u]) - 2; i >= 0; i--) order[u] = max(order[u], get_order(g[u][i]) + 1);
    return order[u];
}

void solve_testcase(int tc) {
    string s;
    cin >> s;
    int n = len(s), cnt = 0;
    order = vi(n, -1);
    g = vec<vi>(n);
    stack<int> st;
    st.push(0);
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') st.push(++cnt);
        if (s[i] == ')') {
            int v = st.top();
            st.pop();
            add(st.top(), v);
        }
        if (s[i] == '-') i++;
    }
    cout << get_order(0) << "\n";
}

int main() {
    const bool MULTITEST = false, STRESS_TEST = false;
#ifdef ONLINE_JUDGE
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#else
    if (STRESS_TEST) {
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    }
#endif
    int tests;
    if (MULTITEST) cin >> tests;
    else tests = 1;
    rep(i, 0, tests) solve_testcase(i + 1);
#ifndef ONLINE_JUDGE
    cout << "Press any key...";
    string s;
    cin >> s;
    exit(0);
#endif
}
