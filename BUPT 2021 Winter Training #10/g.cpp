#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
//const int inf=0x7fffffff;
const int inf = 0x3f3f3f3f;
int t, n;
void solve()
{
    cin >> n;
    vector<string>res(n);
    int ans = 0, temp;
    for (int i = 0; i < n; i++) cin >> res[i];
    for (int j = 0; j < 7; j++)
    {
        temp = 0;
        for (int i = 0; i < n; i++)
        {
            temp += res[i][j] - '0';
        }
        ans = max(ans, temp);
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