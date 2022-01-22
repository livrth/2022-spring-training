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

const int N = 2e6 + 10;
const int INF = 0x3f3f3f3f;
const int maxn = 110;
int a[N];

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        memset(a, 0, sizeof(a));
        vector<int>v;
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
        {
            int x;
            scanf("%d", &x);
            if (!a[x]) v.push_back(x);
            a[x]++;
        }
        int cnt = n / v.size() + 1;
        int ans = INF;
        for (int i = 2; i <= cnt; i++)
        {
            bool flag = 0;
            int sum = 0;
            for (int j = 0; j < v.size(); j++)
            {
                int tot = (a[v[j]] - 1) / i + 1;
                if (a[v[j]] < tot * (i - 1) || a[v[j]] > tot * i)
                {
                    flag = 1;
                    break;
                }
                sum += tot;
            }
            if (flag == 1) continue;
            else ans = min(ans, sum);
        }
        printf("%d\n", ans);
    }
    return 0;
}