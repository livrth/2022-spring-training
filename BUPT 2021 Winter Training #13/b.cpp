#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define um unordered_map
#define pq priority_queue
#define sz(x) ((int)(x).size())
#define x first
#define y second
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

//直接贪心，先从前放大的，后半部分放最小的
const int N = 1005;
int n, x, y, a[N];

void solve() {
    cin >> n >>  x >> y;
    a[1] = x;
    for (int i = 2, cur = n; i <= n / 2 ; i++) {
        while (cur == x || cur == y) --cur;
        a[i] = cur;
        --cur;
    }
    for (int i = n / 2 + 1, cur = 1; i < n; i++) {
        while (cur == x || cur == y) ++cur;
        a[i] = cur;
        ++cur;
    }
    a[n] = y;
    for (int i = 1; i <= n / 2; i++)
        if (a[i] < x) {
            cout << -1 << '\n';
            return;
        }
    for (int i = n / 2 + 1; i <= n; i++)
        if (a[i] > y) {
            cout << -1 << '\n';
            return;
        }
    for (int i = 1; i <= n; i++) cout << a[i] << ' ';
    puts("");
}

int main() {
    int t = 1;
    cin >> t;
    while (t --) solve();
    return 0;
}