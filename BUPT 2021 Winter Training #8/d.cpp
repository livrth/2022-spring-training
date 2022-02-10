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

ll N, K;
int main() {
    scanf("%lld%lld", &N, &K);
    vector<ll> v;
    for(int i = 0; i < N; i++) {
        ll x; scanf("%lld", &x); v.pb(x);
    }
    v.pb(0);
    ll ans = 0;
    ll left = 0;
    for (int i = 0; i < sz(v); i++) {
        ll d = 0;
        if ( left ) {
            ans ++; d = K - left;
        }
        v[i] = max(0LL, v[i] - d);
        ans += v[i] / K; left = v[i] % K;
    }

    cout << ans << endl;

}