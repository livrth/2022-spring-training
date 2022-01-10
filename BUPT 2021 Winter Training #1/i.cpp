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
// const ll mod = 0;
int rnd(int x) { return mrand() % x;}
ll mulmod(ll a, ll b) {ll res = 0; a %= mod; assert(b >= 0); for (; b; b >>= 1) {if (b & 1)res = (res + a) % mod; a = 2 * a % mod;} return res;}
// ll powmod(ll a, ll b) {ll res = 1; a %= mod; assert(b >= 0); for (; b; b >>= 1) {if (b & 1)res = res * a % mod; a = a * a % mod;} return res;}
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a;}
//head

ll pow(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

void solve() {
    ll  n, m;
    cin >> m >> n;
    ll res = 0;
    if (n == 0 && m == 1) res = 1;
    else if (n == 1 && m == 1) res = 2;
    else if (n != 0 && m >= 2) res = pow(2, m) - 1;
    else if (n == 0 && m >= 2) res = pow(2, m);

    cout << res << endl;
    // cout << powmod(2, 2) << endl;
}

int main() {
    int t = 1;
    cin >> t;
    while (t --) solve();
    return 0;
}