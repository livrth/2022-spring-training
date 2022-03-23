#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define SIZE 200010
using namespace std;
vector<pair<int, char> > vec[SIZE];

//https://www.cnblogs.com/st1vdy/p/12752015.html

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n, m; cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a, b; char c;
        cin >> a >> b >> c;
        --a, --b;
        vec[a].emplace_back(mp(b, c));
        vec[b].emplace_back(mp(a, c));
    }

    vector<int> dis(n, -1);
    queue<int> q;
    q.push(n - 1);
    dis[n - 1] = 0;
    while (!q.empty()) {
        int top = q.front();
        q.pop();
        for (auto i : vec[top]) {
            int to = i.first;
            if (dis[to] == -1) {
                dis[to] = dis[top] + 1;
                q.push(to);
            }
        }
    }

    string ans = "";
    vector<int> pa(n, -1);
    vector<int> tmp;
    tmp.emplace_back(0);
    for (int i = 0; i < dis[0]; ++i) {
        char minc = 'z' + 1;
        vector<int> nxt;
        for (auto j : tmp) {
            for (auto k : vec[j]) {
                if (dis[k.first] == dis[j] - 1) {
                    if (k.second < minc) {
                        pa[k.first] = j;
                        minc = k.second;
                        nxt = { k.first };
                    }
                    else if (k.second == minc) {
                        pa[k.first] = j;
                        nxt.emplace_back(k.first);
                    }
                }
            }
        }
        sort(nxt.begin(), nxt.end());
        nxt.erase(unique(nxt.begin(), nxt.end()), nxt.end());
        tmp = nxt;
        ans += minc;
    }

    vector<int> path;
    int fa = n - 1;
    while (fa != -1) {
        path.emplace_back(fa + 1);
        fa = pa[fa];
    }
    reverse(path.begin(), path.end());
    cout << path.size() - 1 << '\n';
    for (auto i : path) cout << i << ' ';
    cout << '\n' << ans;
}