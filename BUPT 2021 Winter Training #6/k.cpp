#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define um unordered_map
#define pq priority_queue
#define sz(x) ((int)(x).size())
// #define x first
// #define y second
#define endl '\n'
typedef vector<int> vi;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
mt19937 mrand(random_device{}());
const ll MOD = 1000000007;
int rnd(int x) { return mrand() % x;}
// ll mulmod(ll a, ll b) {ll res = 0; a %= mod; assert(b >= 0); for (; b; b >>= 1) {if (b & 1)res = (res + a) % mod; a = 2 * a % mod;} return res;}
// ll powmod(ll a, ll b) {ll res = 1; a %= mod; assert(b >= 0); for (; b; b >>= 1) {if (b & 1)res = res * a % mod; a = a * a % mod;} return res;}
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a;}
//head

const int N = 1e5 + 10;

struct node {
    ll x1, y1, x2, y2;
    bool pushdown;
    node(ll x1 = 1, ll y1 = 0, ll x2 = 0, ll y2 = 1) {
        this->x1 = x1;
        this->y1 = y1;
        this->x2 = x2;
        this->y2 = y2;
        pushdown = false;
    }
};

node t[N << 2];
char s[N];
int n, q;

void pushup(node &a, node b, node c) {
    a.x1 = (b.x1 * c.x1 + b.y1 * c.x2) % MOD;
    a.y1 = (b.x1 * c.y1 + b.y1 * c.y2) % MOD;
    a.x2 = (b.x2 * c.x1 + b.y2 * c.x2) % MOD;
    a.y2 = (b.x2 * c.y1 + b.y2 * c.y2) % MOD;
}

void build(int k, int l, int r) {
    if (l == r) {
        if (s[l] == 'A') {
            t[k].x1 = t[k].y1 = t[k].y2 = 1;
            t[k].x2 = 0;
        } else {
            t[k].x1 = t[k].x2 = t[k].y2 = 1;
            t[k].y1 = 0;
        }
        return;
    }
    int m = (l + r) >> 1;
    build(k << 1, l, m);
    build(k << 1 ^ 1, m + 1, r);
    pushup(t[k], t[k << 1 ^ 1], t[k << 1]);
}

void pushdown(int k, int l, int r) {
    if (t[k].pushdown) {
        swap(t[k].x1, t[k].y2);
        swap(t[k].x2, t[k].y1);
        if (l < r) {
            t[k << 1].pushdown ^= 1;
            t[k << 1 ^ 1].pushdown ^= 1;
        }
        t[k].pushdown = false;
    }
}

void update(int k, int l, int r, int x, int y) {
    pushdown(k, l, r);
    if (l > y || r < x) return;
    if (l >= x && r <= y) {
        t[k].pushdown ^= 1;
        pushdown(k, l, r);
        return;
    }
    int m = (l + r) >> 1;
    update(k << 1, l, m, x, y);
    update(k << 1 ^ 1, m + 1, r, x, y);
    pushup(t[k], t[k << 1 ^ 1], t[k << 1]);
}

node query(int k, int l, int r, int x, int y) {
    pushdown(k, l, r);
    if (l > y || r < x) return node();
    if (l >= x && r <= y) return t[k];
    int m = (l + r) >> 1;
    node t1 = query(k << 1, l, m, x, y);
    node t2 = query(k << 1 ^ 1, m + 1, r, x, y);
    node t0;
    pushup(t0, t2, t1);
    return t0;
}

void solve() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> q;
    cin >> s + 1;
    build(1, 1, n);
    while (q--) {
        int id, l, r;
        cin >> id >> l >> r;
        if (id == 1) {
            update(1, 1, n, l, r);
        } else {
            ll a, b;
            cin >> a >> b;
            node t0 = query(1, 1, n, l, r);
            ll A = (t0.x1 * a + t0.y1 * b) % MOD;
            ll B = (t0.x2 * a + t0.y2 * b) % MOD;
            cout << A << " " << B << endl;
        }
    }
}

int main() {
    int t = 1;
    // cin >> t;
    while (t --) solve();
    return 0;
}