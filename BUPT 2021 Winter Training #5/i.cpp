#include <bits/stdc++.h>

using namespace std;
#define endl "\n"
#define ll long long
//const int inf=0x7fffffff;
const int inf = 0x3f3f3f3f;
int t, n;

char Ask(int i, int j) {
    cout << "? " << i << " " << j << endl;
    char ans;
    cin >> ans;
    return ans;
}

void solve() {
    cin >> n;
    int M = 2 * n;
    vector<int> res[2];
    for (int i = 1; i <= M; ++i)
    {
        int which = (res[0].size() <= res[1].size() ? 0 : 1);
        bool ok = true;
        for (int j = 0; j < res[which].size(); ++j)
        {
            if (Ask(res[which][j], i) == '>')
            {
                ok = false;
                res[which].insert(res[which].begin() + j, i);
                break;
            }
        }
        if (ok) res[which].push_back(i);
        if (res[0].size() + res[1].size() > n)
        {
            if (Ask(res[0][0], res[1][0]) == '<')
            {
                res[0].erase(res[0].begin());
            }
            else
            {
                res[1].erase(res[1].begin());
            }
        }
    }
    cout << "!" << endl;
}

int main() {
    cin >> t;
    while (t--)
    {
        solve();
    }
}