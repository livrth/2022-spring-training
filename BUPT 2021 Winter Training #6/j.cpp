#include <bits/stdc++.h>

using namespace std;
#define ll long long
//const int inf=0x7fffffff;
const int inf = 0x3f3f3f3f;
const int maxn = 1e5 + 5;
int t, n, k, g1, g2, g3;
char s[maxn];
int dp[maxn][55];//表示最多可使用type2的数量，第二个元素代表使用type3的数量
int S, R;

void solve() {
    cin >> n >> k >> g1 >> g2 >> g3;
    scanf("%s", s + 1);
    S = 0, R = 0;
    for (int i = 1; i <= n; i++) {
        if (s[i] == '.') S++;
        if (s[i] == '#') R++;
    }
    memset(dp, -1, sizeof(dp));
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= R; j++) {
            if (s[i] == '.') {
                if (s[i + 1] == '.' && dp[i - 1][j] != -1) //禁止不可转移状态
                {
                    dp[i + 1][j] = max(dp[i + 1][j], dp[i - 1][j] + 1);
                }
                if (s[i + 1] == '#' && s[i + 2] == '.' && dp[i - 1][j] != -1) {
                    dp[i + 2][j + 1] = max(dp[i + 2][j + 1], dp[i - 1][j]);
                }
            }
            if (dp[i - 1][j] != -1) dp[i][j] = max(dp[i][j], dp[i - 1][j]);
        }
    }
    ll ans = 0;
    for (int i = 0; i <= R; i++)
    {
        if (dp[n][i] == -1) continue;
        ll temp = dp[n][i] * g2 + i * g3;
        int tk = S - dp[n][i] * 2 - i * 2;
        if (tk >= k)
        {
            temp += k * g1;
            if (temp > ans) ans = temp;
        }
        else
        {
            temp += tk * g1;
            tk = k - tk;
            if (g1 * 2 > g2)
            {
                int num = min(tk / 2, dp[n][i]);
                temp += g1 * 2 * num;
                temp -= num * g2;
                tk -= num * 2;
                dp[n][i] -= num;
            }
            if (tk > 0 && g1 > g2)
            {
                int num = min(tk, dp[n][i]);
                temp += num * g1;
                temp -= num * g2;
            }
        }
        if (temp > ans) ans = temp;
    }
    cout << ans << endl;
}

int main() {
    t = 1;
    while (t--) {
        solve();
    }
    return 0;
}