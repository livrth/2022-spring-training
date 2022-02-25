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

ll readint() {
    ll x = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch > '9') {if (ch == '-')f = -1; ch = getchar();}
    while (ch >= '0' && ch <= '9') {x = x * 10 + ch - '0'; ch = getchar();}
    return x * f;
}

ll k, x;

int main() {
    int T = readint();
    while (T--) {
        k = readint(); x = readint();
        if (1ll * k * (k + 1) / 2 + 1ll * k * (k - 1) / 2 < x) {
            printf("%d\n", k + k - 1);
            continue;
        }
        if (1ll * k * (k + 1) / 2 >= x) {
            ll l = 1, r = k, res = 0;
            while (l <= r) {
                ll mid = (l + r) / 2;
                if (1ll * mid * (mid + 1) / 2 >= x) res = mid, r = mid - 1;
                else l = mid + 1;
            }
            printf("%lld\n", res);
        }
        else {
            x -= 1ll * k * (k + 1) / 2;
            ll l = 1, r = k - 1, res = 0;
            while (l <= r) {
                ll mid = (l + r) / 2;
                if (1ll * (mid + k - 1) * (k - mid) / 2 >= x) res = mid, l = mid + 1;
                else r = mid - 1;
            }
            printf("%lld\n", k + k - res);
        }
    }
    return 0;
}