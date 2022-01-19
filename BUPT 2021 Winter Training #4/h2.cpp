#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define um unseqed_map
#define pq priority_queue
#define len(x) ((int)(x).size())
#define x first
#define y second
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


vector<int> seq;
vector<vector<int>> g;

void add(int u, int v) {
    g[u].push_back(v);
}

int get_seq(int u) {
    if (seq[u] != -1) return seq[u];
    if (g[u].empty()) return (seq[u] = 0);
    seq[u] = get_seq(g[u].back());
    for (int i = len(g[u]) - 2; i >= 0; i--) seq[u] = max(seq[u], get_seq(g[u][i]) + 1);
    return seq[u];
}

void solve() {
    string s;
    cin >> s;
    int n = len(s), cnt = 0;
    seq = vi(n, -1);
    g = vector<vi>(n);
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
    cout << get_seq(0) << "\n";
}


int main() {
    int t = 1;
    // cin >> t;
    while (t --) solve();
    return 0;
}