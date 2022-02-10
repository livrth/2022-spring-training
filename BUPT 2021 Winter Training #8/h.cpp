#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
//const int inf=0x7fffffff;
const int inf = 0x3f3f3f3f;
int t, n, q, ans;
map<string, pair<int, int>>m;
string anss;
string temp;
void solve()
{
    cin >> n;
    vector<string>s(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i];
        for (int j = 0; j < s[i].length(); j++)
        {
            string tt = "";
            for (int k = j; k < s[i].length(); k++)
            {
                tt += s[i][k];
                auto &ttt = m[tt];
                if (ttt.second != i)
                {
                    ttt.first++;
                    ttt.second = i;
                }
            }
        }
    }
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        cin >> temp;
        ans = m[temp].first;
        anss = s[m[temp].second];
        if (ans == 0) anss = "-";
        cout << ans << " " << anss << endl;
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