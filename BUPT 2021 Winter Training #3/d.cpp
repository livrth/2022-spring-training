#include <bits/stdc++.h>
using namespace std;
#define ll long long
//const int inf=0x7fffffff;
const int inf = 0x3f3f3f3f;
const int maxn = 2e5 + 5;
int t, n, m, a, b, c[maxn], sumt, temp;
bool check(int x)
{
    if (x > sumt || x > m || x >= temp) return false;
    for (int i = 1; i <= x; i++)
    {
        if (x - i + c[i] + 1 > sumt) return false;
    }
    return true;
}
void solve()
{
    cin >> n >> m >> a >> b;
    temp = abs(a - b);
    if (b > a) sumt = b - 1;
    else sumt = n - b;
    for (int i = 1; i <= m; i++) cin >> c[i];
    sort(c + 1, c + m + 1);
    int l = 0;
    int r = 2 * m;
    while (l < r)
    {
        int mid = (l + r) >> 1;
        if (check(mid)) l = mid + 1;
        else r = mid;
    }
    cout << l - 1 << endl;
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