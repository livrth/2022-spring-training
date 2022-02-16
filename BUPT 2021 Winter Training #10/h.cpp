#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
//const int inf=0x7fffffff;
const int inf = 1e18;
const int maxn = 1e5 + 5;
int t, n;
ll a[maxn];
ll tt[maxn][2];
ll dp[maxn][2];
void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    tt[1][0] = a[1];
    dp[1][0] = 0;
    for (int i = 2; i <= n; i++) //变为完全递增序列的消耗
    {
        if (a[i] <= tt[i - 1][0])
        {
            tt[i][0] = tt[i - 1][0] + 1;
            dp[i][0] = dp[i - 1][0] + tt[i][0] - a[i];
        }
        else
        {
            tt[i][0] = a[i];
            dp[i][0] = dp[i - 1][0];
        }
    }
    tt[n][1] = a[n];
    dp[n][1] = 0;
    for (int i = n - 1; i >= 1; i--) //变成完全递减序列的消耗
    {
        if (a[i] <= tt[i + 1][1])
        {
            tt[i][1] = tt[i + 1][1] + 1;
            dp[i][1] = dp[i + 1][1] + tt[i][1] - a[i];
        }
        else
        {
            tt[i][1] = a[i];
            dp[i][1] = dp[i + 1][1];
        }
    }
    ll ans = min(dp[n][0], dp[1][1]);
    for (int i = 2; i < n; i++)
    {
        ans = min(ans, dp[i][0] + dp[i][1] - (min(tt[i][0], tt[i][1]) - a[i])); //左边递增右边递减的消耗
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