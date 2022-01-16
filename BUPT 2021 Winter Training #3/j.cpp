#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define um unordered_map
#define pq priority_queue
#define sz(x) ((int)(x).size())
#define x first
#define y second
#define endl '\n'
typedef vector<int> vi;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
mt19937 mrand(random_device{}());
const ll mod = 1000000007;
int rnd(int x) { return mrand() % x;}
ll mulmod(ll a, ll b) {ll res = 0; a %= mod; assert(b >= 0); for (; b; b >>= 1) {if (b & 1)res = (res + a) % mod; a = 2 * a % mod;} return res;}
ll powmod(ll a, ll b) {ll res = 1; a %= mod; assert(b >= 0); for (; b; b >>= 1) {if (b & 1)res = res * a % mod; a = a * a % mod;} return res;}
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a;}
//head

//https://blog.csdn.net/weixin_44178736/article/details/113755391

#define int long long

const int maxm = 2e5 + 5;
struct Node {
    int a, b, c;
} e[maxm];
int pre[maxm];
int n, m, k;
bool cmp(Node a, Node b) {
    return a.c < b.c;
}
int ffind(int x) {
    return pre[x] == x ? x : pre[x] = ffind(pre[x]);
}
void solve() {
    cin >> n >> m >> k;
    int num = 0;
    for (int i = 1; i <= n; i++)pre[i] = i;
    for (int i = 1; i <= m; i++) {
        int a, b, c; cin >> a >> b >> c;
        e[++num] = {a, b, c};
    }
    sort(e + 1, e + 1 + m, cmp);
    int ans = 1e18;
    int cnt = n;
    int pos = 1;
    int ma = -1;
    //将<=k的边全部加入
    for (; pos <= m; pos++) {
        if (e[pos].c > k)break;
        int fa = ffind(e[pos].a);
        int fb = ffind(e[pos].b);
        if (fa != fb) {
            pre[fa] = fb;
            cnt--;
        }
        ma = max(ma, e[pos].c); //记录边权最大值
    }
    if (cnt == 1) { //如果已经联通
        ans = min(ans, k - ma); //第一种方法是将ma加到k.
        for (int i = pos; i <= m; i++) { //第二种方法是选择一条>k的边减到k.
            ans = min(ans, e[i].c - k);
        }
    } else { //如果不连通,那么必须加>k的边
        int sum = 0;
        for (int i = pos; i <= m; i++) {
            int fa = ffind(e[i].a);
            int fb = ffind(e[i].b);
            if (fa != fb) {
                pre[fa] = fb;
                sum += e[i].c - k; //累加总花费
                cnt--;
                if (cnt == 1)break;
            }
        }
        if (cnt == 1)ans = min(ans, sum);
    }
    if (ans == 1e18)ans = -1;
    cout << ans << endl;
}

signed main() {
    int t = 1;
    cin >> t;
    while (t --) solve();
    return 0;
}