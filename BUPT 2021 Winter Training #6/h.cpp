#include <bits/stdc++.h>
using namespace std;
#define ll long long
//const int inf=0x7fffffff;
const int inf = 0x3f3f3f3f;
const int maxn = 1e5 + 5;
int t, n;
struct G
{
    ll a, b;
} g[maxn];
bool cmp(G g1, G g2)
{
    return g1.b > g2.b;
}
void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> g[i].a >> g[i].b;
        if (g[i].a > g[i].b) swap(g[i].a, g[i].b);
    }
    sort(g + 1, g + n + 1, cmp);
    ll ans = g[1].a * g[1].b;
    ll maxa = g[1].a, maxb = g[1].b;
    for (int i = 2; i <= n; i++)
    {
        ans = max(ans, g[i].a * g[i].b);
        ans = max(ans, min(maxa, g[i].a) * g[i].b * 2);
        maxa = max(maxa, g[i].a);
    }
    if (ans & 1) printf("%lld.5\n", (ans - 1) / 2);
    else printf("%lld.0\n", ans / 2);
}
int main()
{
    t = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}