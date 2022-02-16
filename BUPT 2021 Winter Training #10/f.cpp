//模拟过程
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
//const int inf=0x7fffffff;
const int inf = 0x3f3f3f3f;
int t, n, k, m, a, sum, x, y, z;
int v[105], lst[105];
int win[105], can[105];
void solve()
{
    cin >> n >> k >> m >> a;
    int x;
    for (int i = 1; i <= a; i++)
    {
        cin >> x;
        v[x]++;
        lst[x] = i;
    }
    for (int i = 1; i <= n; i++)
    {
        if (v[i] == 0) continue;
        vector<int>res;//需要多少来超过v[i];
        for (int j = 1; j <= n; j++)
        {
            if (i == j) continue;
            if (v[j] > v[i] || (v[j] == v[i] && lst[j] < lst[i])) res.push_back(0);
            else res.push_back(v[i] + 1 - v[j]);
        }
        sort(res.begin(), res.end());
        sum = 0;
        if (k == n)
        {
            win[i] = 1;
        }
        else
        {
            for (int j = 0; j < k; j++)
            {
                sum += res[j];
            }
            if (sum > m - a) win[i] = 1;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (v[i] == 0 && m == a) continue;
        vector<pair<pair<int, int>, int>>res;
        for (int j = 1; j <= n; j++)
        {
            x = v[j], y = lst[j], z = j;
            if (i == j)
            {
                x += m - a;
                y = m;
            }
            x = -x;
            res.push_back(make_pair(make_pair(x, y), z));
        }
        sort(res.begin(), res.end());
        if (n == k)
        {
            can[i] = 1;
        }
        else
        {
            for (int j = 0; j < k; j++)
            {
                if (res[j].second == i)
                {
                    can[i] = 1;
                    break;
                }
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (win[i]) cout << 1 << " ";
        else if (can[i]) cout << 2 << " ";
        else cout << 3 << " ";
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