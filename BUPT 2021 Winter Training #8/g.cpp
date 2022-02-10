#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define um unordered_map
#define pq priority_queue
#define sz(x) ((int)(x).size())
#define fi first
#define se second
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

const int maxn = 107;
int mp[maxn][maxn];
int a[maxn], n, m, s[maxn], h[maxn], vis[maxn], id[maxn];
int ans[maxn], cnt;

void init() { //n^2预处理每个英雄能移动的范围
    for (int i = 1; i <= m; i++) {
        mp[s[i]][s[i]] = h[i];
        int tmp = h[i];
        for (int j = s[i]; j >= 1; j--) {
            if (tmp < 0) mp[s[i]][j] = -1;
            else {
                tmp += a[j];
                mp[s[i]][j] = max(-1, tmp);
            }
        }
        tmp = h[i];
        for (int j = s[i]; j <= n; j++) {
            if (tmp < 0) mp[s[i]][j] = -1;
            else {
                tmp += a[j];
                mp[s[i]][j] = max(-1, tmp);
            }
        }
    }
}

void print(int x) { //打印答案
    printf("%d\n", x);
    for (int i = 1; i <= m; i++) {
        if (!vis[i]) ans[++cnt] = i;
    }
    for (int i = 1; i < cnt; i++) printf("%d ", ans[i]);
    printf("%d\n", ans[cnt]);
}

bool check(int x, int y) { // 查找剩余区间是否有英雄
    for (int i = x; i <= y; i++) {
        if (id[i]) return 0;
    }
    return 1;
}

void solve() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; i++) {
        scanf("%d%d", &s[i], &h[i]);
        id[s[i]] = i;
    }
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    init();
    a[0] = a[n + 1] = 0;
    for (int i = 1; i <= n; i++) { //枚举集结点
        // 将集结点归在左区间
        memset(vis, 0, sizeof vis);
        int tmp = i; //目前走到的位置
        cnt = 0;
        bool f = 0; //标记集结点是否走过
        for (int j = i; j >= 1; j--) {
            if (id[j] && mp[j][tmp] >= 0) {
                vis[id[j]] = 1;
                ans[++cnt] = id[j];
                tmp = j - 1;
                f = 1;
            }
        }
        if (check(0, tmp)) {
            if (f == 0) tmp = i;
            else tmp = i + 1;
            for (int j = tmp; j <= n; j++) {
                if (id[j] && mp[j][tmp] >= 0) {
                    vis[id[j]] = 1;
                    ans[++cnt] = id[j];
                    tmp = j + 1;
                }
            }
            if (check(tmp, n + 1)) {
                print(i);
                return;
            }
        }

        memset(vis, 0, sizeof vis);
        cnt = 0;
        tmp = i; f = 0;
        for (int j = i; j <= n; j++) {
            if (id[j] && mp[j][tmp] >= 0) {
                vis[id[j]] = 1;
                ans[++cnt] = id[j];
                tmp = j + 1;
                f = 1;
            }
        }
        if (check(tmp, n + 1)) {
            if (f == 0) tmp = i;
            else tmp = i - 1;
            for (int j = tmp; j >= 1; j--) {
                if (id[j] && mp[j][tmp] >= 0) {
                    vis[id[j]] = 1;
                    ans[++cnt] = id[j];
                    tmp = j - 1;
                }
            }
            if (check(0, tmp)) {
                print(i);
                return;
            }
        }
    }
    printf("-1\n");
}

int main() {
    int t = 1;
    // cin >> t;
    while (t --) solve();
    return 0;
}