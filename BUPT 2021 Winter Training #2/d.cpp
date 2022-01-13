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

ll pow(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

void solve() {
    string s;
    int ans = 0;
    cin >> s;
    int len = sz(s);
    int l = pow(10, len - 1);
    int r = pow(10, len) - 1;
    if (l == 1) l = 0;
    while (l % 25 != 0) l++; //first number can x | 25
    for (; l < r; l += 25) {
        string cur = to_string(l);
        char xx = '#';
        bool flag = 1;
        for (int i = 0; s[i]; i++) {
            if (s[i] == '_') continue;
            if (s[i] == 'X') {
                if (xx != '#' && xx != cur[i]) {
                    flag = 0;
                    break;
                }
                xx = cur[i];
            }
            else if (s[i] != cur[i]) {
                flag = 0;
                break;
            }
        }
        ans += flag;
    }
    cout << ans << endl;
}

int main() {
    int t = 1;
    // cin >> t;
    while (t --) solve();
    return 0;
}