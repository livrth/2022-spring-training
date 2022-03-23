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

void solve() {
    int n; cin >> n;
    map<int, vector<int> > mp;
    for (int i = 1; i <= n; ++i) {
        int x, y;
        cin >> x >> y;
        mp[y].emplace_back(x);
    }
    auto check = [&](vector<int>& a, vector<int>& b) {
        for (int i = 0; i < a.size(); ++i)
            if (a[i] != b[i])
                return true;
        return false;
    };
    for (auto it : mp) {
        vector<int> a, b;
        a = b = it.second;
        sort(a.begin(), a.end());
        if (check(a, b)) {
            cout << "NO";
            return;
        }
    }
    cout << "YES";
}

int main() {
    int t = 1;
    // cin >> t;
    while (t --) solve();
    return 0;
}