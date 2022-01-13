#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MX = 1e5 + 10;
const ll mod = 1e9 + 7;

int n, arr[MX], cnt[MX];
int phi[MX];
vector<int> d[MX];

void precalc_phi() {
    phi[0] = 0;
    phi[1] = 1;
    for (int i = 2; i < MX; i ++)
        phi[i] = i;

    for (int i = 2; i < MX; i ++)
        if (phi[i] == i)
            for (int j = i; j < MX; j += i)
                phi[j] -= phi[j] / i;
}

void precalc_divisors() {
    for (int i = 1; i < MX; i ++)
        for (int j = i; j < MX; j += i)
            d[j].push_back(i);
}

void solve() {
    precalc_phi();
    precalc_divisors();

    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> arr[i];

    ll ans = 0ll;
    for (int x = 1; x <= n; x ++) {
        for (int i = x; i <= n; i += x)
            for (int j : d[arr[i]])
                cnt[j] ++;

        for (int i = x; i <= n; i += x)
            for (int j : d[arr[i]])
                if (cnt[j]) {
                    (ans += phi[x] * (phi[j] * 1ll * (cnt[j] * 1ll * cnt[j] % mod) % mod) % mod) %= mod;
                    cnt[j] = 0;
                }
    }
    cout << ans << endl;
}

int main() {
    solve();
    return 0;
}