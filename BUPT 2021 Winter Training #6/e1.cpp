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

//https://blog.csdn.net/qq_43690454/article/details/108319515

const int N = 1e5 + 10;
int up[N], down[N], a[N];
int l, r, n, k;

void solve() {
    scanf("%d %d %d %d", &n, &l, &r, &k);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    up[n] = r; down[n] = l;
    for (int i = n - 1; i >= 1; i--) {
        if (a[i] == a[i + 1]) up[i] = up[i + 1], down[i] = down[i + 1];
        else if (a[i] < a[i + 1]) {
            up[i] = up[i + 1] - 1;
            down[i] = max(l, down[i + 1] - k);
        }
        else if (a[i] > a[i + 1]) {
            down[i] = down[i + 1] + 1;
            up[i] = min(r, up[i + 1] + k);
        }
        if (up[i] < down[i] || up[i] > r || down[i] < l) {
            puts("-1");
            return;
        }
    }
    // for (int i = 1; i <= n; i++) cout << up[i] << " " << down[i] << endl;
    int now = down[1];
    printf("%d ", now);
    for (int i = 2; i <= n; i++) {
        if (a[i] == a[i - 1]) ;
        else if (a[i] < a[i - 1]) {
            now = max(down[i], now - k);
        }
        else if (a[i] > a[i - 1]) {
            now = max(down[i], now + 1);
        }
        printf("%d ", now);
    }
    puts(" ");
}

int main() {
    int t = 1;
    // cin >> t;
    while (t --) solve();
    return 0;
}