#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
//const int inf=0x7fffffff;
const int inf = 0x3f3f3f3f;
const int maxn = 3e5 + 5;
int t, n, m, s;
int si[maxn], a[maxn], b[maxn], vis[maxn], fa[maxn];
vector<vector<int>>e(maxn);
int dfs(int x)
{
    int res = 1;
    vis[x] = 1;
    for (auto to : e[x])
    {
        if (!vis[to])
        {
            fa[to] = x;
            res += dfs(to);
        }
    }
    return res;
}
void solve()
{
    cin >> n >> m >> s;
    for (int i = 1; i <= m; i++)
    {
        cin >> si[i] >> a[i] >> b[i];
        if (si[i] == 2) e[b[i]].push_back(a[i]);
        e[a[i]].push_back(b[i]);
    }
    cout << dfs(s) << endl;
    for (int i = 1; i <= n; i++) e[i].clear(), vis[i] = 0;
    for (int i = 1; i <= m; i++)
    {
        if (si[i] == 1) e[a[i]].push_back(b[i]); //只保留有向边
        if (si[i] == 2)
        {
            if (fa[b[i]] == a[i]) cout << "+";
            else cout << "-";
        }
    }
    cout << endl;
    cout << dfs(s) << endl;
    for (int i = 1; i <= m; i++)
    {
        if (si[i] == 2)
        {
            if (vis[a[i]])
            {
                cout << "-";
            }
            else cout << "+";
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