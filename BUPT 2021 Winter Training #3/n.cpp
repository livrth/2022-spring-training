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

void solve() {
    int c1, c2, c3;
    std::cin >> c1 >> c2 >> c3;
    int a1, a2, a3, a4, a5;
    std::cin >> a1 >> a2 >> a3 >> a4 >> a5;
    if (a1 <= c1 && a2 <= c2 && a3 <= c3 && a1 + a3 + a4 <= c1 + c3 && a2 + a3 + a5 <= c2 + c3 && a1 + a2 + a3 + a4 + a5 <= c1 + c2 + c3) {
        std::cout << "YES\n";
    } else {
        std::cout << "NO\n";
    }
}

int main() {
    int t = 1;
    cin >> t;
    while (t --) solve();
    return 0;
}