#include <bits/stdc++.h>

using namespace std;
using ll = long long int;
using pll = pair<ll, ll>;

#define FOR(i, n, m) for(ll i = (m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;
const long double PI = 3.1415926535897932384626433832795028841971;

int isInside(double ax, double ay, double bx, double by, double cx, double cy, double tx, double ty) {
    double abXat, bcXbt, caXct;

    abXat = (bx - ax) * (ty - ay) - (by - ay) * (tx - ax);
    bcXbt = (cx - bx) * (ty - by) - (cy - by) * (tx - bx);
    caXct = (ax - cx) * (ty - cy) - (ay - cy) * (tx - cx);

    if ((abXat > 0.0 && bcXbt > 0.0 && caXct > 0.0) || (abXat < 0.0 && bcXbt < 0.0 && caXct < 0.0)) {
        return 1;
    } else if (abXat * bcXbt * caXct == 0.0) {
        return 0;
    }

    return 0;

}

bool check(vector<pll> T, ll index) {
    vector<pll> t;
    REP(i, 4) {
        if (i == index)
            continue;
        t.push_back(T[i]);
    }
    return isInside(t[0].first, t[0].second, t[1].first, t[1].second, t[2].first, t[2].second, T[index].first,
                    T[index].second);
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    vector<pll> T(4);
    REP(i, 4) {
        cin >> T[i].first >> T[i].second;
    }

    REP(i, 4) {
        if (check(T, i)) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}