#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define um unordered_map
#define pq priority_queue
#define sz(x) ((int)(x).size())
#define x first
#define y second
#define endl '\n'
typedef vector<int> vi;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
mt19937 mrand(random_device{}());
const ll mod = 1000000007;
int rnd(int x) { return mrand() % x;}
ll mulmod(ll a, ll b) {ll res = 0; a %= mod; assert(b >= 0); for (; b; b >>= 1) {if (b & 1)res = (res + a) % mod; a = 2 * a % mod;} return res;}
ll powmod(ll a, ll b) {ll res = 1; a %= mod; assert(b >= 0); for (; b; b >>= 1) {if (b & 1)res = res * a % mod; a = a * a % mod;} return res;}
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a;}
//head

vector<string> text;

const string str_begin = "\\begin{thebibliography}{99}",
             str_end = "\\end{thebibliography}",
             str_cite = "\\cite";

void solve() {
    while (true) {
        string line;
        getline(cin, line);
        if (line == str_begin) break;
        text.push_back(line);
    }

    vector<string> order;
    for (auto &s : text) {
        for (int i = 0; i + 4 < s.length(); ++i) {
            if (s.substr(i, 5) == str_cite) {
                int l = s.find('{', i);
                int r = s.find('}', i);
                order.push_back(s.substr(l + 1, r - l - 1));
            }
        }
    }
    vector< pair<string, string> > item;
    map<string, string> item_map;
    while (true) {
        string line;
        getline(cin, line);
        if (line == str_end) break;
        int l = line.find('{');
        int r = line.find('}');
        item.push_back({line.substr(l + 1, r - l - 1), line});
    }
    bool correct = true;
    for (int i = 0; i < order.size(); ++i) {
        item_map[item[i].first] = item[i].second;
        if (order[i] != item[i].first) correct = false;
    }
    puts(correct ? "Correct" : "Incorrect");
    if (correct) return;
    puts(str_begin.c_str());
    for (int i = 0; i < order.size(); ++i) {
        puts(item_map[order[i]].c_str());
    }
    puts(str_end.c_str());

}

int main() {
    int t = 1;
    // cin >> t;
    while (t --) solve();
    return 0;
}