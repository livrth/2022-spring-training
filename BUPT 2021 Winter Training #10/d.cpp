#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
//const int inf=0x7fffffff;
const int inf = 0x3f3f3f3f;
const int maxn = 2e5 + 5;
int t, n, T;
int x;
void solve()
{
    cin >> n >> T;
    int ans = 0;
    priority_queue<int>q;
    for (int i = 1; i <= min(n, T - 1); i++)
    {
        cin >> x;
        while (!q.empty() && q.top() >= T - i) q.pop(); //去掉等待时间最长的碗
        if (max(x, i) < T) q.push(x - i);
        ans = max(ans, int(q.size()));
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