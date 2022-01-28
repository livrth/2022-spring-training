#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
//const int inf=0x7fffffff;
const ll inf = 1ll << 62;
const int maxnn = 2000000100;
const int maxn = 2e7 + 5;
const ll MOD = 4294967296;
int a[maxn];
unsigned int b[maxn];
int n, t;
ll l, r, x, y, z;
void solve()
{
    cin >> n >> l >> r >> x >> y >> z >> b[1] >> b[2];
    for (int i = 3; i <= n; i++)
    {
        b[i] = (b[i - 2] * x + b[i - 1] * y + z) % MOD;
    }
    for (int i = 1; i <= n; i++)
    {
        a[i] = (b[i] % (r - l + 1)) + l;
    }
    int minn = maxnn;
    ll ans = inf;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] > minn) {
            ans = min(ans, (ll)a[i] * minn);
        }
        minn = min(minn, a[i]);
    }
    minn = -maxnn;
    for (int i = n; i >= 1; i--) //全是负数的情况
    {
        if (a[i] < minn) {
            ans = min(ans, (ll)a[i] * minn);
        }
        minn = max(minn, a[i]);
    }
    if (ans == inf) cout << "IMPOSSIBLE" << endl;
    else cout << ans << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}