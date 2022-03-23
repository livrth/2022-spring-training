#include <bits/stdc++.h>

using namespace std;
#define endl "\n"
using ll = long long;
//constexpr int inf=0x7fffffff;
constexpr int inf = 0x3f3f3f3f;
constexpr int P = 998244353;
auto seed = chrono::system_clock::now().time_since_epoch().count();
mt19937 rnd(seed);

template<typename T>
T rd(T l, T r) { return uniform_int_distribution<T>(l, r)(rnd); }

int n;
ll a[200005];

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    ll ans = 0, res = 1;
    sort(a + 1, a + n + 1, greater<int>());
    for (int i = 1; i <= n; i++) {
        if (a[i] > res) {
            ans += a[i] - res;
            res++;
        }
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int _t = 1;
    while (_t--) {
        solve();
    }
    return 0;
}