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

//https://blog.csdn.net/qq_49451105/article/details/114442263
//假设 小于 b 的和大于 b 的元素个数都 >(k-1)/2
//但是大于的和小于的数量是不一样的
//那么就先从多的那部分开始删，直到删除到和少的一样
//最后再考虑把b作为中位数删除b左右的，也就是只要存在一个b满足，那么总有方法删完

const int N = 2e5 + 5;
int n, m, k;
int p[N], b[N];

void solve() {
    cin >> n >> k >> m;
    for (int i = 1; i <= n; i++) p[i] = 0;
    for (int i = 1; i <= m; i++)
        scanf("%d", &b[i]), p[b[i]] = 1;
    if ((n - m) % (k - 1)) {
        puts("NO"); return;
    }
    int t = 0; k = (k - 1) >> 1;
    for (int i = 1; i <= n; i++) {
        if (!p[i]) t++;
        else if (t >= k && n - m - t >= k) {
            puts("YES"); return;
        }
    }
    puts("NO");
}

int main() {
    int t = 1;
    cin >> t;
    while (t --) solve();
    return 0;
}