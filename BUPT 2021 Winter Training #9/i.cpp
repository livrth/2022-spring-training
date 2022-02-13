#include<bits/stdc++.h>
#define ll long long
using namespace std;

//https://blog.csdn.net/qq_50808324/article/details/113775864
//二分+DP

int n, k, a[300010], ans, f[300010];
bool ok(int t) {
    for (int i = 1; i <= n; i++) f[i] = 0;
    f[0] = 1;
    int l = 1, r;
    for (int i = 1; i <= n; i++) {
        while (a[i] - a[l] > t) l++;
        r = i - k + 1;
        for (int j = l; j <= r; j++) if (f[j - 1]) {
                f[i] = 1;
                break;
            }
            else l++;
    }
    return f[n];
}

int main() {
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    sort(a + 1, a + 1 + n);
    int l = 0, r = a[n];
    while (l <= r) {
        int mid = l + r >> 1;
        if (ok(mid)) {
            ans = mid;
            r = mid - 1;
        }
        else l = mid + 1;

    }
    printf("%d", ans);
    return 0;
}