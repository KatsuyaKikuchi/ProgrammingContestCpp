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

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, W;
    cin >> N >> W;
    vector<pll> V(N);
    REP(i, N) {
        cin >> V[i].first >> V[i].second;
    }

    vector<vector<vector<ll>>> dp(N + 5, vector<vector<ll>>(N + 5, vector<ll>(3 * N + 5, 0)));

    REP(i, N) {
        REP(j, N + 1) {
            REP(k, 3 * N + 2) {
                ll w = j * V[0].first + k;
                dp[i + 1][j][k] = std::max(dp[i + 1][j][k], dp[i][j][k]);
                if (V[i].first + w <= W) {
                    dp[i + 1][j + 1][k + V[i].first - V[0].first] =
                            std::max(dp[i + 1][j + 1][k + V[i].first - V[0].first],
                                     dp[i][j][k] + V[i].second);
                }
            }
        }
    }

    ll ans = 0;
    REP(i, N + 1) {
        REP(j, dp[N][i].size()) {
            ans = std::max(ans, dp[N][i][j]);
        }
    }
    cout << ans << endl;
    return 0;
}