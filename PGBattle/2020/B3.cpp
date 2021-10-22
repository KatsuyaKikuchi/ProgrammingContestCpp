#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <queue>
#include <stack>
#include <iomanip>
#include <cmath>
#include <map>
#include <set>

using namespace std;
using ll = long long int;
using pll = pair<ll, ll>;

#define FOR(i, n, m) for(ll i = (m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;
const long double PI = 3.1415926535897932384626433832795028841971;

ll dp[1005][1005][4];
ll x[4] = {0, -1, 0, 1};
ll y[4] = {-1, 0, 1, 0};

ll nxtDir(ll n) {
    if (n == 0)
        return 3;
    if (n == 1)
        return 0;
    if (n == 2)
        return 1;
    return 2;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll H, W;
    cin >> H >> W;
    pll s, g;
    cin >> s.first >> s.second >> g.first >> g.second;
    s.first--;
    s.second--;
    g.first--;
    g.second--;
    vector<string> M(H);
    REP(i, H) {
        cin >> M[i];
    }
    REP(i, H) {
        REP(j, W) {
            REP(k, 4) {
                dp[i][j][k] = INF;
            }
        }
    }

    ll dir = 0;
    dp[s.first][s.second][dir] = 0;
    while (true) {
        bool update = false;
        ll cost = dp[s.first][s.second][dir] + 1;
        REP(i, 4) {
            ll n = (dir + i) % 4;
            ll nx = x[n] + s.first, ny = y[n] + s.second;
            if (nx < 0 || ny < 0 || nx >= H || ny >= W)
                continue;
            if (M[nx][ny] == '#')
                continue;
            ll nxt = nxtDir(n);
            if (dp[nx][ny][nxt] <= cost)
                break;
            dp[nx][ny][nxt] = cost;
            update = true;
            dir = nxt;
            s = pll(nx, ny);
            break;
        }

        if (!update)
            break;
    }

    ll ans = INF;
    REP(i, 4) {
        ans = std::min(ans, dp[g.first][g.second][i]);
    }
    if (ans == INF)ans = -1;
    cout << ans << endl;
    return 0;
}