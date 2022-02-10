#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
//const int inf=0x7fffffff;
const int inf = 0x3f3f3f3f;
const int maxn = 4e5 + 5;
int t, n;
vector<int>v1;//10
vector<int>v2;//01
vector<int>v3;//00;
vector<int>res;
ll ans;
string s;
void solve()
{
    cin >> n;
    int x;
    ans = 0;
    int flag = 0;
    int flag1 = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> s >> x;
        if (s == "11") flag++, ans += x;
        else if (s == "10") v1.push_back(x);
        else if (s == "01") v2.push_back(x);
        else res.push_back(x);
    }
    sort(v1.begin(), v1.end(), greater<int>());
    sort(v2.begin(), v2.end(), greater<int>());
    for (int i = 0; i < v1.size() && i < v2.size(); i++)
    {
        ans += v1[i];
        ans += v2[i];
        flag1++;
        flag++;
    }
    if (v1.size() > v2.size())
    {
        for (int i = v2.size(); i < v1.size(); i++)
        {
            res.push_back(v1[i]);
        }
    }
    else if (v2.size() > v1.size())
    {
        for (int i = v1.size(); i < v2.size(); i++)
        {
            res.push_back(v2[i]);
        }
    }
    sort(res.begin(), res.end(), greater<int>());
    for (int i = 0; i < res.size() && flag1 < flag; i++, flag1++)
    {
        ans += res[i];
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