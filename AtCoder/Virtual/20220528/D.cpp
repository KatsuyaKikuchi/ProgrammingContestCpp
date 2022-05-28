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

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll H, W, N;
    cin >> H >> W >> N;
    std::set<pll> center;
    std::set<pll> grid;
    REP(i, N) {
        ll a, b;
        cin >> a >> b;
        grid.insert(pll(a, b));
        REP(x, 3) {
            REP(y, 3) {
                pll g(a + x - 1, b + y - 1);
                if (g.first >= 2 && g.first <= H - 1 && g.second >= 2 && g.second <= W - 1)
                    center.insert(g);
            }
        }
    }

    vector<ll> ans(10, 0);
    for (auto c: center) {
        ll count = 0;
        REP(x, 3) {
            REP(y, 3) {
                pll g(c.first + x - 1, c.second + y - 1);
                if (grid.find(g) != grid.end())
                    count++;
            }
        }

        ans[count]++;
    }

    ans[0] = (H - 2) * (W - 2);
    FOR(i, ans.size(), 1) {
        ans[0] -= ans[i];
    }

    REP(i, 10) {
        cout << ans[i] << endl;
    }

    return 0;
}