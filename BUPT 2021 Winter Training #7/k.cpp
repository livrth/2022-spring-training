#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define um unordered_map
#define pq priority_queue
#define sz(x) ((int)(x).size())
#define S second
#define F first
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
typedef pair < string, int > psi;
vector < vector < psi > > grps;
map < int, int > M;
vector < vector < int > > ans;

int main() {
    int n; cin >> n;
    M.clear();
    for (int i = 1; i <= n; i++) {
        string s, t; cin >> s >> t;
        int msk = 0;
        for (int j = 0; j < t.size(); j++) {
            msk |= 1 << (t[j] - 'a');
        }
        if (M.find(msk) == M.end()) {
            M[msk] = grps.size();
            grps.pb(* new vector < psi > ());
        }
        while (s.size() > 0 && (msk & (1 << (s.back() - 'a')))) s.pop_back();
        grps[M[msk]].pb({s, i});
    }

    for (vector < psi > grp : grps) {
        sort(grp.begin(), grp.end());
        for (int j = 0; j < grp.size();) {
            int i = j; ans.pb({grp[i].S});
            while (i + 1 < grp.size() && grp[i + 1].F == grp[i].F)
                i++, ans[ans.size() - 1].pb(grp[i].S);
            j = i + 1;
        }
    }

    cout << ans.size() << endl;
    for (auto z : ans) {
        cout << z.size() << " ";
        for (int e : z) {
            cout << e << " ";
        }
        cout << endl;
    }
}
