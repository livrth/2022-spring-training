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

long double dp[111][11111], ans;
ll a[111], n, k, x;

void solve() {
    int i, j, k;
    cin >> n >> x; dp[0][0] = 1;
    for (i = 1 ; i <= n ; i++) cin >> a[i];
    for (i = 1 ; i <= n ; i++)
        for (j = i - 1 ; j >= 0 ; j--)
            for (k = 0 ; k <= 10000 ; k++)
                dp[j + 1][k + a[i]] += dp[j][k] * (j + 1) / (n - j);
    for (i = 1 ; i <= n ; i++)
        for (j = 1 ; j <= 10000 ; j++)
            ans += min((1.0 * n / i + 1) * x / 2, 1.0 * j / i) * dp[i][j];
    cout << fixed << setprecision(15) << ans;
}

int main() {
    int t = 1;
    // cin >> t;
    while (t --) solve();
    return 0;
}

