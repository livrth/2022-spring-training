#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
//const int inf=0x7fffffff;
const int inf = 0x3f3f3f3f;
const int maxn = 1e5 + 5;
unordered_set<int>s[maxn];
int t, n, m;
int x, y;
int a[maxn];
int b[maxn];
void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> x >> y;
        s[x].insert(y);
        s[y].insert(x);
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == j) continue;
            if (!s[i].count(j))
            {
                cout << "YES" << endl;
                int cnt = 0;
                for (int k = 1; k <= n; k++)
                {
                    if (k == i || k == j) continue;
                    a[k] = ++cnt;
                    b[k] = cnt;
                }
                a[i] = cnt + 1;
                a[j] = cnt + 2;
                b[i] = cnt + 1;
                b[j] = cnt + 1;
                for (int k = 1; k <= n; k++) cout << a[k] << " ";
                cout << endl;
                for (int k = 1; k <= n; k++) cout << b[k] << " ";
                cout << endl;
                return;
            }
        }
    }
    cout << "NO" << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    t = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}