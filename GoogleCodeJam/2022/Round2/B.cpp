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

void draw_circle_filled(ll R, vector<vector<bool>> &P) {
    for (ll x = -R; x <= R; ++x) {
        for (ll y = -R; y <= R; ++y) {
            if (round(sqrt(x * x + y * y)) <= R) {
                P[x + R][y + R] = true;
            }
        }
    }
}

void draw_circle_perimeter(ll r, ll R, vector<vector<bool>> &W) {
    for (ll x = -r; x <= r; ++x) {
        ll y = round(sqrt(r * r - x * x));
        W[x + R][y + R] = true;
        W[x + R][-y + R] = true;
        W[y + R][x + R] = true;
        W[-y + R][x + R] = true;
    }
}

void draw_circle_filled_wrong(ll R, vector<vector<bool>> &W) {
    for (ll r = 0; r <= R; ++r) {
        draw_circle_perimeter(r, R, W);
    }
}

ll solve() {
    ll R;
    cin >> R;
    vector<vector<bool>> P(2 * R + 1, vector<bool>(2 * R + 1, false));
    vector<vector<bool>> W(2 * R + 1, vector<bool>(2 * R + 1, false));
    draw_circle_filled(R, P);
    draw_circle_filled_wrong(R, W);

    ll ret = 0;
    REP(i, P.size()) {
        REP(j, P[i].size()) {
            if (P[i][j] != W[i][j])
                ret++;
        }
    }

#if false
    cout << endl;
    REP(i, P.size()) {
        REP(j, P.size()) {
            if (P[i][j])
                cout << "#";
            else
                cout << " ";
        }
        cout << endl;
    }
    cout << "--------" << endl;
    REP(i, W.size()) {
        REP(j, W.size()) {
            if (W[i][j])
                cout << "#";
            else
                cout << " ";
        }
        cout << endl;
    }
    cout << "--------" << endl;
#endif
    return ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll T;
    cin >> T;
    REP(i, T) {
        cout << "Case #" << i + 1 << ": " << solve() << endl;
    }
    return 0;
}