#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
//const int inf=0x7fffffff;
const int inf = 0x3f3f3f3f;
int t, n, a, b, k, f;
void solve()
{
    cin >> n >> a >> b >> k >> f;
    vector<pair<string, string>>s(n);
    map<pair<string, string>, int> mp;
    int ans = a, temp;
    for (int i = 0; i < n; i++)
    {
        cin >> s[i].first >> s[i].second;
    }
    vector<pair<string, string>>resss = s;
    if (resss[0].first > resss[0].second) swap(resss[0].first, resss[0].second);
    mp[resss[0]] += ans;
    for (int i = 1; i < n; i++)
    {
        temp = ans;
        if (s[i].first == s[i - 1].second) ans += b;
        else ans += a;
        if (resss[i].first > resss[i].second) swap(resss[i].first, resss[i].second);
        mp[resss[i]] += ans - temp;
    }
    int flag = 0;
    vector<int>ress;
    for (auto x : mp)
    {
        ress.push_back(x.second);
        //cout<<x.first.first<<" "<<x.first.second<<" "<<x.second<<endl;
    }
    sort(ress.begin(), ress.end());
    for (int i = ress.size() - 1; i >= 0; i--)
    {
        if (flag == k) break;
        if (ress[i] <= f) break;
        ans -= ress[i];
        ans += f;
        flag++;
        if (flag == k) break;
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