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

const int N = 1010;
ll f[N][N];
double g[N][N];

int main() {
    int n; scanf("%lld", &n);
    for (int k = 0; k < n; k++) {
        vector<int> a(5);
        for (int i = 0 ; i < 5 ; i++) {
            scanf("%lld", &a[i]);
            f[k][i] = a[i];
        }
        sort(all(a));

        if (a[0] <= 3) g[k][0] = 1;
        else if (a[0] == 4) g[k][0] = 0.9, g[k][1] = 0.1;
        else if (a[0] <= 7) g[k][1] = 1;
        else if (a[0] == 8)  g[k][1] = 0.9,  g[k][0] = 0.1;
        else if (a[0] <= 13)  g[k][2] = 1;
        else if (a[0] <= 19)  g[k][3] = 1;
        else if (a[0] <= 29)  g[k][4] = 1;

        for (int j = 0; j < 5; j++) {
            printf("%.01lf ", g[k][j]);
        }
        printf("\n"); fflush(stdout);
    }
    return 0;
}