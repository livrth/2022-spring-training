#include <bits/stdc++.h>
using namespace std;

const int inf = 0x3f3f3f3f;
const int N = 105;
int n, m, mi = inf;
int a[N][N];
vector<int> ans;
vector<int> tmp;

struct P {
    int val, id;
} sta[N];

bool cmp(P a, P b) {
    return a.val > b.val;
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    for (int i = 1; i <= n - 1; i++) {
        tmp.clear();
        for (int j = 1; j <= m; j++) {
            sta[j].val = a[j][i] - a[j][n];
            sta[j].id = j;
        }
        sort(sta + 1, sta + 1 + m, cmp);
        int sum = 0;
        for (int j = 1; j <= m; j++) {
            if (sum + sta[j].val >= 0) sum += sta[j].val;
            else tmp.push_back(sta[j].id);
        }
        if (tmp.size() < mi) {
            ans = tmp;
            mi = tmp.size();
        }
    }
    printf("%d\n", mi);
    for (int i = 0; i < ans.size(); i++) {
        printf("%d ", ans[i]);
    }
    return 0;
}