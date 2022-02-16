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
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++ i)
        scanf("%d", &a[i]);
    vector<int> last(n, -1);
    vector<vi> ans(n);
    for (int i = 0; i < n; i++) {
        int k = (int)(upper_bound(last.begin(), last.end(), a[i], greater<int>()) - last.begin());
        ans[k].push_back(a[i]);
        last[k] = a[i];
    }
    for (int k = 0; k < n; k++)
        if (last[k] != -1) {
            for (int i = 0; i < (int)ans[k].size(); ++ i) {
                if (i != 0) putchar(' ');
                printf("%d", ans[k][i]);
            }
            puts("");
        }
}

int main() {
    int t = 1;
    // cin >> t;
    while (t --) solve();
    return 0;
}