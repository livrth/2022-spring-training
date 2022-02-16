#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
//const int inf=0x7fffffff;
const int inf = 0x3f3f3f3f;
int t, n;
int a[105];
void solve()
{
    cin >> n;
    bool ok = true;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    int d = a[2] - a[1];
    for (int i = 3; i <= n; i++)
    {
        if (a[i] - a[i - 1] != d)
        {
            ok = false;
            break;
        }
    }
    if (ok) cout << a[n] + d << endl;
    else cout << a[n] << endl;
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