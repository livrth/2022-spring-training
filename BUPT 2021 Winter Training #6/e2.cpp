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

//https://frozenguardian.blog.csdn.net/article/details/108358721
//从后往前能先求出每个元素的最大范围
//然后从前往后递推即可，从前往后递推时，a[1]=l[1]

const int N = 1e5 + 100;
int a[N], l[N], r[N];

void solve() {
    int n, L, R, k;
    scanf("%d%d%d%d", &n, &L, &R, &k);
    for (int i = 1; i <= n; i++)
        scanf("%d", a + i);
    auto check = [&]()
    {
        l[n] = L, r[n] = R;
        for (int i = n - 1; i >= 1; i--)
        {
            if (a[i] == a[i + 1])
            {
                l[i] = l[i + 1];
                r[i] = r[i + 1];
            }
            else if (a[i] < a[i + 1])
            {
                l[i] = max(L, l[i + 1] - k);
                r[i] = r[i + 1] - 1;
            }
            else if (a[i] > a[i + 1])
            {
                l[i] = l[i + 1] + 1;
                r[i] = min(R, r[i + 1] + k);
            }
            if (l[i] > r[i] || l[i] < L || r[i] > R)
                return false;
        }
        return true;
    };
    if (!check()) {
        puts("-1");
        return;
    }
    int ans = l[1];
    for (int i = 1; i <= n; i++)
    {
        printf("%d ", ans);
        if (a[i] == a[i + 1])
            continue;
        else if (a[i] > a[i + 1])
            ans = max(ans - k, l[i + 1]);
        else if (a[i] < a[i + 1])
            ans = max(ans + 1, l[i + 1]);
    }
    puts("");
}

int main() {
    int t = 1;
    // cin >> t;
    while (t --) solve();
    return 0;
}