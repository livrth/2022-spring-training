#include<bits/stdc++.h>
using namespace std;

//https://blog.csdn.net/qq_42479630/article/details/104287416
string str[1010];
int n, l, k, m, change;

int main() {
    scanf("%d%d%d", &n, &l, &k);
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    if (k == 1) {
        for (int i = 1; i <= l; ++i) str[k] += s[m], m++;
    }
    else {
        for (int i = 1; i <= k; ++i) str[i] += s[m], m++;
        int t = str[k].size();
        for (int i = 1; i <= k; ++i) {
            if (str[i][t - 1] == str[k][t - 1]) {change = i; break;}
        }

        while (str[k].size() < l) {
            if (change != k) {
                for (int i = change; i <= k; ++i) str[i] += s[m], m++;
                t = str[k].size();
                for (int i = change; i <= k; ++i) if (str[i][t - 1] == str[k][t - 1]) {change = i; break;}
            }
            else {
                while (str[k].size() < l) str[k] += s[m], m++;
                break;
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        while (str[i].size() < l) str[i] += s[m], m++;
    }
    for (int i = 1; i <= n; ++i) cout << str[i] << endl;

    return 0;
}