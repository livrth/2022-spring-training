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

const int maxn = 200005;
int a[maxn], s[maxn];
int n, m;
long long t;

bool check(int x) {
    long long sum = 0;
    long long tmp = 0;
    int d = s[x], cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (cnt == x) break;
        if (a[i] <= d) {
            if (cnt && cnt % m == 0) {sum += tmp; tmp = 0;}
            sum += a[i];
            tmp += a[i];
            cnt++;
        }
    }
    return sum <= t;
}

void solve() {
    cin >> n >> m >> t;
    for (int i = 1; i <= n; i++) {cin >> a[i]; s[i] = a[i];}
    sort(s + 1, s + n + 1);
    s[0] = 1;
    int l = 1, r = n;
    int ans = 0;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (check(mid)) {ans = mid; l = mid + 1;}
        else r = mid - 1;
    }
    printf("%d %d\n", ans, s[ans]);
}

int main() {
    int t = 1;
    cin >> t;
    while (t --) solve();
    return 0;
}