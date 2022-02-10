#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
//const int inf=0x7fffffff;
const int inf = 0x3f3f3f3f;
const int maxn = 3e4 + 5;
int t, n, m, k;
int cur[26], dp[maxn];
string s;
ll ans;
void func(int x)
{
    for (int i = 0; i <= n; i++) dp[i] = 0;
    dp[0] = 1;
    for (int i = 0; i < 26; i++)
    {
        if (i == x) continue;
        for (int j = n; j >= 0; j--)
        {
            if (dp[j] && j + cur[i] <= n)
            {
                dp[j + cur[i]] = 1;
            }
        }
    }
    int left = k - n - m;
    for (int i = n; i >= 0 && i + cur[x] >= n; i--)
    {
        if (!dp[i]) continue;
        int res = cur[x] - (n - i) - left;
        if (res < 0) res = 0;
        ll temp = 1LL * min(res, m) * (n - i);
        if (temp < ans) ans = temp;
    }
}
void solve()
{
    memset(cur, 0, sizeof(cur));
    cin >> n >> m >> k;
    cin >> s;
    for (int i = 0; i < k; i++)
    {
        cur[s[i] - 'A']++;
    }
    ans = 1LL * n * m;
    for (int i = 0; i < 26; i++)
    {
        if (cur[i]) func(i); //作为n的额外补充和多余的部分
    }
    cout << ans << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}