#include <bits/stdc++.h>
using namespace std;
typedef long long LL;


//https://blog.csdn.net/qq_45458915/article/details/108379858

const int inf = 0x3f3f3f3f;
const int N = 1e5 + 100;
multiset<LL>st;

struct Seg {
    LL pos, t;
    bool flag;//开始点:0,结束点:1
    Seg(LL pos, LL t, bool flag): pos(pos), t(t), flag(flag) {}
    bool operator<(const Seg& t)const {
        if (pos != t.pos)
            return pos < t.pos;
        return flag < t.flag;
    }
};

vector<Seg> segment;

void solve() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        LL l, r, t;
        scanf("%lld%lld%lld", &l, &r, &t);
        segment.push_back(Seg(l + t, t, 0));
        segment.push_back(Seg(r, t, 1));
    }
    sort(segment.begin(), segment.end()); //按照l[i]+t[i]升序排序，满足情况1
    LL ans = 0, pre = 0;
    for (auto t : segment) {
        if (!st.empty()) //如果当前有房子开放
        {
            LL num = (t.pos - pre) / (*st.begin()); //贪心计算贡献
            ans += num;
            pre += num * (*st.begin());
        }
        if (t.flag) //结束点
            st.erase(st.find(t.t));
        else//开始点
        {
            if (pre + t.t <= t.pos) //到达开始点l[i]+t[i]时就可以铸一把剑了
            {
                ans++;
                pre = t.pos;
            }
            st.insert(t.t);
        }
    }
    printf("%lld\n", ans);
}

int main() {
    int t = 1;
    // cin >> t;
    while (t -- ) solve();
    return 0;
}