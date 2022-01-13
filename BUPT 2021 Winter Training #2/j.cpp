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

int find(vector<vector<int >> &p, int x, int y) {
    return p[x][y] = p[x][y] == x ? x : find(p, p[x][y], y);
}

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> a(n + 2, vector<int>(m + 1));
    vector<vector<int>> p(n + 2, vector<int>(m + 1, n + 1));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
            p[i][j] = i;
            if (a[i][j] == 2) p[i][j] = i + 1;
        }
    while (k --) {
        int y;
        cin >> y;
        int x = 1;
        while (x != n + 1) {
            if (a[x][y] == 1) {
                a[x][y] = 2;
                p[x][y] = x + 1;
                y++;
            }
            else if (a[x][y] == 3) {
                a[x][y] = 2;
                p[x][y] = x + 1;
                y --;
            }
            else {
                find(p, x, y);
                x = p[x][y];
            }
        }
        cout << y <<  ' ';
    }
}

int main() {
    int t = 1;
    // cin >> t;
    while (t --) solve();
    return 0;
}