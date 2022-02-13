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

char in[105];
char u[105];
set <string> Sx;

void solve() {
    int N, i, j;
    scanf("%d", &N);
    while (N--) {
        scanf("%s", in);
        int L = 0;
        for (i = 0; in[i] != 0; i++) {
            if (in[i] == 'u') {
                u[L] = 'o';
                u[L + 1] = 'o';
                L += 2;
            }
            else if (in[i] == 'h') {
                while (L >= 1 && u[L - 1] == 'k') L--;
                u[L++] = in[i];
            }
            else u[L++] = in[i];
        }
        u[L] = 0;
        Sx.emplace(u);
    }
    printf("%d\n", (int)Sx.size());
}

int main() {
    int t = 1;
    // cin >> t;
    while (t --) solve();
    return 0;
}
