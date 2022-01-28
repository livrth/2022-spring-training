#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define um unordered_map
#define pq priority_queue
#define sz(x) ((int)(x).size())
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

ll t, n, a, b, k;

bool chk(ll t) {
    return t * k <= (n + 1) / 2 * min(a, t) + n / 2 * min(b, t);
}

void solve() {
    cin >> t >> n >> a >> b >> k;
    ll l = 0, r = t, ans = 0;
    for (; l <= r;) {
        ll mid = l + r >> 1;
        if (chk(mid)) ans = mid, l = mid + 1;
        else r = mid - 1;
    }
    cout << ans << endl;
}

int main() {
    int t = 1;
    // cin >> t;
    while (t --) solve();
    return 0;
}