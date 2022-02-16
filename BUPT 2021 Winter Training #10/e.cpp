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

const int N = 210000;
char a[N]; int n;

bool check(int S) {
    int pre = 0;
    int now = 0;
    for (int i = 1; i <= n; i++)
        if (a[i] == '*') {
            if (i > now && (!pre))pre = i;
        }
        else if (a[i] == 'P') {
            if (!pre)pre = i;
            if (i - pre > S)return 0;
            now = max(now, min(n, S + 2 * pre - i));
            now = max(now, min(n, (S + i + pre) / 2));
            pre = 0;
        }
    return (!pre);
}

void solve() {
    scanf("%d", &n);
    scanf("%s", a + 1);
    int l = 1; int r = 2 * n;
    int ans = 0;
    while (l < r) {
        int mid = (l + r) >> 1;
        if (check(mid))ans = mid, r = mid;
        else l = mid + 1;
    }
    if (check(l))ans = l;
    printf("%d\n", ans);
}

int main() {
    int t = 1;
    // cin >> t;
    while (t --) solve();
    return 0;
}