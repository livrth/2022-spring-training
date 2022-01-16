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

pq<pii> q;
const int N = 5e5 + 10;
int n, f[N], m;
int a = 1;

void solve() {
    cin >> n;
    while (n --) {
        int t;
        cin >> t;
        if (t == 1) {
            int p;
            m++;
            cin >> p;
            q.push({p, -m});
        }
        else if (t == 2) {
            while (f[a]) a++;
            f[a] = 1;
            cout << a << ' ';
        }
        else {
            while (f[-q.top().y])q.pop();
            f[-q.top().y] = 1;
            cout << -q.top().y << ' ';
            q.pop();
        }
    }
}

int main() {
    int t = 1;
    // cin >> t;
    while (t --) solve();
    return 0;
}