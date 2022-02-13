#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
//const int inf=0x7fffffff;
const ll inf = 1e18;
int _t;
ll a[3], t[3], p[3];
ll calc(ll f, ll T)
{
    if (T <= 0) return inf;
    if (t[0] <= t[2])
    {
        if (f * t[0] <= T) return 0;
        else return inf;
    }
    if (f * t[2] > T) return inf;
    ll res = (f * t[0] - T + a[2] * (t[0] - t[2]) - 1) / (a[2] * (t[0] - t[2])); //t[0]不够的用t[2]来填充
    if (res < 0) res = 0;
    if (res > (f + a[2] - 1) / a[2]) return inf;
    else return res * p[2];
}
void solve()
{
    ll f, T, ans;
    cin >> f >> T >> t[0];
    for (int i = 1; i <= 2; i++)
    {
        cin >> a[i] >> t[i] >> p[i];
    }
    if (t[0]*f <= T)
    {
        cout << 0 << endl;
        return;
    }
    if (t[2] < t[1]) swap(a[1], a[2]), swap(t[1], t[2]), swap(p[1], p[2]);
    if (f * t[1] <= T) ans = (f + a[1] - 1) / a[1] * p[1];
    else ans = inf;
    for (ll i = 0; i <= f / a[1]; i++)
    {
        ll sum = calc(f - i * a[1], T - i * a[1] * t[1]);
        if (sum != inf)
        {
            ans = min(ans, sum + i * p[1]);
        }
    }
    cout << (ans == inf ? -1 : ans) << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    _t = 1;
    while (_t--)
    {
        solve();
    }
    return 0;
}