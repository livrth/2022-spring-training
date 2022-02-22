#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
//const int inf=0x7fffffff;
const int inf = 0x3f3f3f3f;
const int maxn = 2e5 + 5;
int a[maxn], bmax[maxn], bmin[maxn], cmax[maxn], cmin[maxn];
int t, n;
void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    bmax[n] = a[n], bmin[n] = a[n];
    cmax[1] = a[1], cmin[1] = a[1];
    for (int i = n - 1; i >= 1; i--)
    {
        bmax[i] = max(bmax[i + 1], a[i]);
        bmin[i] = min(bmin[i + 1], a[i]);
    }
    for (int i = 2; i <= n; i++)
    {
        cmax[i] = max(cmax[i - 1], a[i]);
        cmin[i] = min(cmin[i - 1], a[i]);
    }
    cout << 1 << " ";
    for (int i = 2; i <= n; i++) //分类讨论
    {
        if (cmax[i - 1] >= bmax[i] && cmin[i - 1] >= bmin[i]) cout << 0 << " ";
        else if (cmax[i - 1] >= bmax[i] && cmin[i - 1] < bmin[i])
        {
            cout << fixed << setprecision(10) << 1.0 - (1.0 * cmin[i - 1]) / (1.0 * bmin[i]) << " ";
        }
        else if (cmax[i - 1] < bmax[i] && cmin[i - 1] >= bmin[i])
        {
            cout << fixed << setprecision(10) << 1.0 - (1.0 * cmax[i - 1]) / (1.0 * bmax[i]) << " ";
        }
        else
        {
            cout << fixed << setprecision(10) << 1.0 - min((1.0 * cmax[i - 1]) / (1.0 * bmax[i]), (1.0 * cmin[i - 1]) / (1.0 * bmin[i])) << " ";
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    t = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}