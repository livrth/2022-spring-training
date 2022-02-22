#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
//const int inf=0x7fffffff;
const int inf = 0x3f3f3f3f;
int t, n;
ll a, b, c, d, e, f, g;
void solve()
{
    cin >> a >> b >> c >> d >> e >> f >> g;
    cout << (a * b + c * d)*e*f*g << endl;
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