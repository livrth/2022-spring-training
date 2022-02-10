#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
//const int inf=0x7fffffff;
const int inf = 0x3f3f3f3f;
const int maxn = 1e6 + 5;
int t;
int n, k, m;
vector<pair<int, int>>in[maxn];
vector<pair<int, int>>out[maxn];
ll val[maxn << 2], sum[maxn << 2];
void pushup(int p) {
    val[p] = val[p << 1] + val[p << 1 | 1];
    sum[p] = sum[p << 1] + sum[p << 1 | 1];
}
void build(int l = 1, int r = maxn - 1, int p = 1) {
    if (l == r) {
        val[p] = 0;
        sum[p] = 0;
        return;
    }
    int mid = (l + r) >> 1;
    build(l, mid, p << 1);
    build(mid + 1, r, p << 1 | 1);
    pushup(p);
}
void update(int a, int b, int v, int l = 1, int r = maxn - 1, int p = 1) {
    if (l == a && r == b) {
        val[p] += v;
        sum[p] += (v * (ll)r);
        return;
    }
    ll mid = (l + r) >> 1;
    if (b <= mid) {
        update(a, b, v, l, mid, p << 1);
    }
    else {
        update(a, b, v, mid + 1, r, p << 1 | 1);
    }
    pushup(p);
}
ll query(int xx, int l = 1, int r = maxn - 1, int p = 1) {
    if (val[p] <= xx) return sum[p];
    if (l == r) {
        ll tt = xx <= val[p] ? xx : val[p];
        return (tt * r);
    }
    ll mid = (l + r) >> 1;
    if (val[p << 1] >= xx) return query(xx, l, mid, p << 1);
    return (query(val[p << 1], l, mid, p << 1) + query(xx - val[p << 1], mid + 1, r, p << 1 | 1));
}
int a, b, c, d;
void solve()
{
    cin >> n >> k >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> a >> b >> c >> d;
        in[a].push_back(make_pair(c, d));
        out[b].push_back(make_pair(-c, d));
    }
    build();
    ll ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (auto x : in[i])
        {
            update(x.second, x.second, x.first);
        }
        ans += query(k);
        for (auto x : out[i])
        {
            update(x.second, x.second, x.first);
        }
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