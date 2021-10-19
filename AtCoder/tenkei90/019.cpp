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

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    vector<ll> A(2 * N);
    REP(i, A.size()) {
        cin >> A[i];
    }

    vector<vector<ll>> dp(2 * N + 5, vector<ll>(2 * N + 5, INF));
    REP(left, A.size()) {
        FOR(right, A.size(), left + 1) {

        }
    }
    REP(d, N) {
        ll nxt = 2 * d + 1;
        REP(i, A.size() - nxt) {
            ll cost = (nxt == 1 ? 0 : dp[i + 1][i + nxt - 1]);
            dp[i][i + nxt] = std::min(dp[i][i + nxt], cost + abs(A[i] - A[i + nxt]));
            FOR(j, i + nxt, i + 1) {
                dp[i][i + nxt] = std::min(dp[i][i + nxt], dp[i][j] + dp[j + 1][i + nxt]);
            }
        }
    }

    cout << dp[0][2 * N - 1] << endl;
    return 0;
}