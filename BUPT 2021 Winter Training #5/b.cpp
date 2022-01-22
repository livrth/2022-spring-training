#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
//const int inf=0x7fffffff;
const int inf = 0x3f3f3f3f;
const int maxn = 3e5 + 5;
int t, n, m;
int a[maxn];
string s;
void solve()
{
    cin >> s;
    m = s.length();
    if (m < 2)
    {
        cout << 0 << endl;
        return;
    }
    bool ok = true;
    for (int i = 1; i < m; i++)
    {
        if (s[i] != s[i - 1])
        {
            ok = false;
            break;
        }
    }
    int flag = 1;
    if (ok)
    {
        if (m < 2) cout << 0 << endl;
        else cout << m + 1 << endl;
        return;
    }
    map<int, char>m1;
    s = " " + s;
    a[flag] = 1;
    m1[1] = s[1];
    for (int i = 2; i <= m; i++)
    {
        if (s[i] != s[i - 1])
        {
            flag++;
            m1[flag] = s[i];
            a[flag] = 1;
        }
        else a[flag]++;
    }
    if (flag % 2 == 0)
    {
        cout << 0 << endl;
        return;
    }
    for (int i = 1, j = flag; i < j; i++, j--)
    {
        if (m1[i] != m1[j] || a[i] + a[j] < 3)
        {
            cout << 0 << endl;
            return;
        }
    }
    if (a[flag / 2 + 1] < 2)
    {
        cout << 0 << endl;
        return;
    }
    cout << a[flag / 2 + 1] + 1 << endl;
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