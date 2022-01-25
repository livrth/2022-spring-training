#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define um unordered_map
#define pq priority_queue
#define sz(x) ((int)(x).size())
#define ff first
#define ss second
#define endl '\n'
typedef vector<int> vi;
typedef long long ll;
#define pll pair<ll, ll>
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
    int n;
    vector<pll>ara;
    ll maxi = 0, ar, maxi1 = 0;
    scanf("%d", &n);
    pll tmp;
    for (int i = 1; i <= n; i++) {
        cin >> tmp.ff >> tmp.ss;
        if (tmp.ff > tmp.ss)
            swap(tmp.ff, tmp.ss);
        ara.push_back(tmp);
    }
    sort(all(ara));
    ll l = ara.back().ss;
    maxi1 = ara.back().ff * ara.back().ss;
    for (int i = n - 2; i >= 0; i--) {
        ll len = min(ara[i].ss, l);
        ll xx = ara[i].ff * len;
        maxi = max(maxi, xx);
        l = max(l, ara[i].ss);
        ll yy = ara[i].ff * ara[i].ss;
        maxi1 = max(maxi1, yy);
    }
    double ans = max(maxi * 1.0, (maxi1 * 1.0) / 2.0);
    printf("%0.1f\n", ans);
}

int main() {
    int t = 1;
    // cin >> t;
    while (t --) solve();
    return 0;
}