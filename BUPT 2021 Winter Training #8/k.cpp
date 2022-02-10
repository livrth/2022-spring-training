#include <bits/stdc++.h>
using namespace std;

const int M = 1024 * 256;
int n, k, sum;
int T[M];

void solve() {
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", T + i);
        sum += T[i];
    }
    if (sum % k != 0) {
        printf("No\n");
        return;
    }

    int qwe = sum / k;
    vector<int> V;
    int tmp = 0, il = 0;
    for (int i = 0; i < n; i++) {
        tmp += T[i];
        il++;
        if (tmp > qwe) {
            printf("No\n");
            return;
        }
        if (tmp == qwe) {
            V.push_back(il);
            il = 0;
            tmp = 0;
        }
    }
    if (tmp != 0) {
        printf("No\n");
        return;
    }
    printf("Yes\n");
    for (auto x : V) {
        printf("%d ", x);
    }
    printf("\n");
}

int main() {
    solve();
    return 0;
}