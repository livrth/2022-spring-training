#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define um unordered_map
#define pq priority_queue
// #define sz(x) ((int)(x).size())
#define fi first
#define se second
#define endl '\n'
typedef vector<int> vi;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
mt19937 mrand(random_device{}());
const ll mod = 1000000007;
int rnd(int x) { return mrand() % x;}
ll mulmod(ll a, ll b) {ll res = 0; a %= mod; assert(b >= 0); for (; b; b >>= 1) {if (b & 1)res = (res + a) % mod; a = 2 * a % mod;} return res;}
ll powmod(ll a, ll b) {ll res = 1; a %= mod; assert(b >= 0); for (; b; b >>= 1) {if (b & 1)res = res * a % mod; a = a * a % mod;} return res;}
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a;}
//head

const int N = 1e5 + 10;
const int M = N;
vector<pair<int, pii>> edges;
ll MAX[M], W[M];
int a[M];
int sz[M], p[M];
int n, m;

int find(int x) {
    if (x != p[x]) {
        p[x] = find(p[x]);
    }
    return p[x];
}

void merge(int a, int b, int w) {
    a = find(a); b = find(b);
    if (a == b) return;
    if (sz[a] < sz[b]) swap(a, b); //启发式
    MAX[a] = max(min(MAX[b], 1ll * w) - W[a], min(MAX[a], 1ll * w) - W[b]);
    W[a] += W[b];
    p[b] = a; sz[a] += sz[b];
}

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 0; i <= n; i++) p[i] = i, sz[i] = 1;
    for (int i = 0; i <= n; i++) MAX[i] = 0x3f3f3f3f, W[i] = a[i];

    for (int i = 1; i <= m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        edges.pb({w, {a, b}});
    }
    sort(all(edges));
    reverse(all(edges));
    for (auto &t : edges) merge(t.se.fi, t.se.se, t.fi);
    auto root = find(1);
    if (sz[root] != n || MAX[root] < 1) {
        cout << -1 << endl;
        return;
    }
    cout << MAX[root] << endl;
}

int main() {
    int t = 1;
    // cin >> t;
    while (t --) solve();
    return 0;
}