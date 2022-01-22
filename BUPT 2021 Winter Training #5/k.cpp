#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> P;
const int maxn = 100100;

int a[24];

LL C(int n, int m) {
    LL c = 1LL;
    for (int i = 0; i < m; i++)
        c = c * (n - i) / (i + 1);
    return c;
}

LL solve(int num) {
    LL res = 1;
    int sum = 0;
    for (int i = num + 1; i >= 1; i--) {
        if (num + 1 - i - sum < a[i])return 0LL;
        res *= C(num + 1 - i - sum, a[i]);
        sum += a[i];
    }
    return res;
}


int main() {
    int t, n, i, j, num;
    LL k;
    scanf("%d", &t);
    while (t--) {
        scanf("%I64d", &k);
        i = 2, num = 0;
        memset(a, 0, sizeof(a));
        while (k) {
            a[k % i]++;
            k /= i;
            i++;
            num++;
        }
        LL ans = solve(num);
        if (a[0]) {
            a[0]--;
            ans -= solve(num - 1);
        }
        printf("%I64d\n", ans - 1);
    }
    return 0;
}


