#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define um unordered_map
#define pq priority_queue
#define sz(x) ((int)(x).size())
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

void solve() {
    ll n, t; cin >> n >> t;
    vector<ll> pos, neg;
    for (int i = 0; i < n; ++i) {
        ll x; cin >> x;
        if (x < 0) neg.emplace_back(-x);
        else pos.emplace_back(x);
    }
    sort(neg.begin(), neg.end());
    sort(pos.begin(), pos.end());
    ll ans = 0;
    for (int i = 0; i < neg.size(); ++i) {
        if (neg[i] > t) break;
        ll maxd = t - neg[i] - neg[i];
        ll res = 0;
        if (maxd > 0) res = upper_bound(pos.begin(), pos.end(), maxd) - pos.begin();
        ans = max(ans, i + res + 1);
    }
    for (int i = 0; i < pos.size(); ++i) {
        if (pos[i] > t) break;
        ll maxd = t - pos[i] - pos[i];
        ll res = 0;
        if (maxd > 0) res = upper_bound(neg.begin(), neg.end(), maxd) - neg.begin();
        ans = max(ans, i + res + 1);
    }
    cout << ans;
}

int main() {
    int t = 1;
    // cin >> t;
    while (t --) solve();
    return 0;
}