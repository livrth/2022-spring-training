#include <bits/stdc++.h>

#define db double
#define ll long long
#define ld long double
#define ull unsigned long long
#define vint vector <int>
#define vpii vector <pii>

#define pii pair <int,int>
#define fi first
#define se second
#define pb emplace_back
#define mem(x,v,s) memset(x,v,sizeof(x[0])*(s))
#define cpy(x,y,s) memcpy(x,y,sizeof(x[0])*(s))

inline int read() {
    int x = 0; char s = getchar();
    while (!isdigit(s))s = getchar();
    while (isdigit(s))x = x * 10 + s - '0', s = getchar();
    return x;
}

const ld eps = 1e-6;
const ll N = 2e5;

ld max(ld x, ld y) {return x > y ? x : y;}
ld min(ld x, ld y) {return x < y ? x : y;}
bool Eq(ld x, ld y) {return fabs(x - y) < eps;}
bool Isz(ld x) {return fabs(x) < eps;}

ld up, down, left, right;
ld dis(ld x1, ld y1, ld x2, ld y2) {return sqrt((x1 - x2) * (x1 - x2) + ((y1 - y2) * (y1 - y2)));}
ld dis(ld x1, ld y1, ld x2, ld y2, ld r) {
    ld dot = x1 * x2 + y1 * y2, d = dis(0, 0, x2, y2);
    if (dot < eps)return max((ld)0, d - r);
    ld nd = dot / dis(0, 0, x1, y1);
    return max((ld)0, sqrt(d * d - nd * nd) - r);
}

int swp, type;
void ref(int &x, int &y) {int t = y; y = x, x = -t;} // counterclockwise rotate
ld query(int x, int y) {
    for (int j = 1; j <= swp; j++)ref(x, y);
    std::cout << "? " << x << " " << y << std::endl;
    ld res; std::cin >> res; return res;
}
void answ(int x, int y, int r) {
    for (int j = 1; j <= swp; j++)ref(x, y);
    std::cout << "! " << x << " " << y << " " << r << std::endl, exit(0);
}
void answer(ld x, ld y, ld r) {
    int xx = x < 0 ? x - eps : x + eps, yy = y < 0 ? y - eps : y + eps;
    return answ(xx, yy, r + eps);
}

int main() {
    up = query(0, 10), down = query(0, -10), left = query(-10, 0), right = query(10, 0);
    type = Isz(up) + Isz(down) + Isz(left) + Isz(right);
    if (type == 0) {
        ld mx = max(max(up, down), max(left, right));
        if (down == mx && right == mx)swp = 1;
        if (right == mx && up == mx)swp = 2;
        if (up == mx && left == mx)swp = 3;
    }
    if (type == 1) {if (Isz(left))swp = 1; if (Isz(down))swp = 2; if (Isz(right))swp = 3;}
    if (type == 2) {
        if (Isz(left) && Isz(up))swp = 1;
        if (Isz(down) && Isz(left))swp = 2;
        if (Isz(right) && Isz(down))swp = 3;
    }
    up = query(0, 10), down = query(0, -10), left = query(-10, 0), right = query(10, 0);

    int l = 1, r = N * 2 - 1, xx, yy, tx, ty; ld res;
    while (l < r) {
        int m = l + r >> 1;
        xx = -min(N, m), yy = N - max(0, m - N);
        (res = query(xx, yy)) > 1e-6 ? r = m : l = m + 1;
    } xx = -min(N, l), yy = N - max(0, l - N);
    ld upl = query(tx, ty); ref(tx, ty), ref(tx, ty);
    ld downr = query(tx, ty), mdis = std::min(upl, downr);

    int xx2, yy2; l = 1, r = N * 3 - 1;
    while (l < r) {
        int m = (l + r >> 1) + 1;
        xx2 = min(N, m), yy2 = -N + max(0ll, m - N);
        (res = query(xx2, yy2) > 1e-6) ? l = m : r = m - 1;
    } xx2 = min(N, l), yy2 = -N + max(0, l - N), res = query(xx2, yy2);

    for (int r = 1; r <= 1e5; r++) {
        ld y = mdis + r, x = sqrt((down + r) * (down + r) - y * y);
        ll d = 1ll * xx * xx + 1ll * yy + yy;
        ld sn = (ld)fabs(yy) / (ld)(sqrt(d)); // rotate the plane by some angle
        ld cs = (ld)fabs(xx) / (ld)(sqrt(d));
        if (Eq(mdis, upl))x = -x;
        ld x0 = x * cs + y * sn, y0 = -x * sn + y * cs; x = x0, y = y0;
        if (Eq(res, dis(xx2, yy2, x, y, r)))answer(x, y, r);
    }
    return 0;
}