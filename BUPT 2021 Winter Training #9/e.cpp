#include <bits/stdc++.h>
using namespace std;

int chk[26], seen[26];

char str[110], words[110];

int main() {
    int n; scanf("%d%s", &n, str);
    for (int i = 0; i < n; i++) {
        if (str[i] == '*') continue;
        seen[str[i] - 'a'] = 1;
    }
    int m; scanf("%d", &m);
    for (int i = 0; i < 26; i++) chk[i] = !seen[i];
    for (int i = 0; i < m; i++) {
        scanf("%s", words);
        bool flg = 1;
        int state = 0;
        for (int j = 0; flg && j < n; j++) {
            if (str[j] != '*') {
                if (str[j] != words[j]) flg = 0;
            } else {
                if (seen[words[j] - 'a']) flg = 0;
                state |= 1 << (words[j] - 'a');
            }
        }
        if (!flg) continue;
        for (int j = 0; j < 26; j++) chk[j] &= state >> j & 1;
    }
    int ans = 0;
    for (int j = 0; j < 26; j++) ans += chk[j];
    cout << ans << endl;
    return 0;
}