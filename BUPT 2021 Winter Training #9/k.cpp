#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
//const int inf=0x7fffffff;
const int inf = 0x3f3f3f3f;
int t, n;
const int maxn = 2e5 + 5;
int a[maxn], b[maxn], c[maxn];
void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i] >> b[i];
        c[i] = a[i] + b[i];
    }
    for (int i = 1; i < n; i++)
    {
        c[i + 1] = min(c[i + 1], c[i] + 1);
    }
    for (int i = n; i > 1; i--)
    {
        c[i - 1] = min(c[i - 1], c[i] + 1);
    }
    ll sum = 0;
    for (int i = 1; i <= n; i++)
    {
        if (c[i] < a[i])
        {
            cout << -1 << endl;
            return;
        }
        sum += c[i] - a[i] + 0LL;
    }
    cout << sum << endl;
    for (int i = 1; i <= n; i++) cout << c[i] << " ";
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