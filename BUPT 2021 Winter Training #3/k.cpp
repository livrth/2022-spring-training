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
    string s;
    cin >> s;
    int len = sz(s);
    auto move = [&](int &x, int &y, char d) {
        if (d == 'L') {
            x--;
        } else if (d == 'R') {
            x++;
        } else if (d == 'D') {
            y--;
        } else {
            y++;
        }
    };
    for (int i = 0; i < len; i++) {
        int x = 0, y = 0;
        for (int j = 0; j <= i; j++) move(x, y, s[j]);
        int px = x, py = y;
        x = 0, y = 0;
        for (int j = 0; j < len; j++) {
            int tempx = x, tempy = y;
            move(tempx, tempy, s[j]);
            if (tempx != px || tempy != py) {
                x = tempx;
                y = tempy;
            }
        }
        if(x == 0 && y == 0){
            cout << px << ' ' << py << ' ' << endl;
            return;
        }
    }
    cout << 0 << ' ' << 0 << endl;
}

int main() {
    int t = 1;
    cin >> t;
    while (t --) solve();
    return 0;
}