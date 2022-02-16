#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
//const int inf=0x7fffffff;
const int inf = 1e9;
const int maxx = log(inf);
int t, temp, tt;
char a[255][255];
int res[255][255];
int vis[255][255];
int n, m, p, q;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
struct NODE
{
    int x, y, step;
};
int fst(int a, int b)
{
    int resss = 1;
    while (b)
    {
        if (b & 1) resss *= a;
        a *= a;
        b >>= 1;
    }
    return resss;
}
void bfs(int xx, int yy)
{
    memset(vis, 0, sizeof(vis));
    queue<NODE>q;
    q.push({xx, yy, 0});
    temp = (a[xx][yy] - 'A' + 1) * p;
    while (!q.empty())
    {
        auto [x, y, z] = q.front();
        q.pop();
        if (vis[x][y] == 1) continue;
        if (z > maxx) break;
        tt = fst(2, z);
        if (tt > temp) break;
        res[x][y] += temp / tt;
        vis[x][y] = 1;
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx <= 0 || nx > n || ny <= 0 || ny > m || a[nx][ny] == '*' || vis[nx][ny]) continue;
            q.push({nx, ny, z + 1});
        }
    }
}
void solve()
{
    cin >> n >> m >> p >> q;
    int ans = 0;
    memset(res, 0, sizeof(res));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (a[i][j] == '*') res[i][j] = 0;
            else if (a[i][j] >= 'A' && a[i][j] <= 'Z') bfs(i, j);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (res[i][j] > q) ans++;
        }
    }
    cout << ans << endl;
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