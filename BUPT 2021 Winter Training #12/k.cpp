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
    int x;
    stack<int>s[3];
    set<int>ss[3];
    int flag = 1;
    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        if (x == flag)
        {
            cout << 1 << endl;
            cout << -1 << endl;
            flag++;
        }
        else
        {
            cout << 1 << endl;
            s[1].push(x);
            ss[1].insert(x);
        }
    }
    while (!ss[1].empty() || !ss[2].empty())
    {
        if (ss[1].count(flag))
        {
            x = s[1].top();
            if (x != flag)
            {
                cout << 12 << endl;
                s[2].push(x);
                ss[2].insert(x);
            }
            else
            {
                cout << -1 << endl;
                flag++;
            }
            s[1].pop();
            ss[1].erase(x);
        }
        else
        {
            x = s[2].top();
            if (x != flag)
            {
                cout << 21 << endl;
                s[1].push(x);
                ss[1].insert(x);
            }
            else
            {
                cout << -2 << endl;
                flag++;
            }
            s[2].pop();
            ss[2].erase(x);
        }
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