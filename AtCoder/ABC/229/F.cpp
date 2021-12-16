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

struct Edge {
    ll a, b;
    ll cost;
};

ll dp[200005][2][2];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;

    vector<ll> A(N), B(N);
    REP(i, N) {
        cin >> A[i];
    }
    REP(i, N) {
        cin >> B[i];
    }

    REP(i, N + 1) {
        dp[i][0][0] = dp[i][0][1] = dp[i][1][0] = dp[i][1][1] = INF;
    }
    dp[1][0][0] = A[0];
    dp[1][1][1] = 0;
    FOR(i, N, 1) {
        dp[i + 1][0][0] = std::min(dp[i][0][0] + B[i - 1] + A[i], dp[i][1][0] + A[i]);
        dp[i + 1][1][0] = std::min(dp[i][0][0], dp[i][1][0] + B[i - 1]);
        dp[i + 1][0][1] = std::min(dp[i][0][1] + B[i - 1] + A[i], dp[i][1][1] + A[i]);
        dp[i + 1][1][1] = std::min(dp[i][0][1], dp[i][1][1] + B[i - 1]);
    }

    ll ans = std::min({
                              dp[N][0][0] + B[N - 1],
                              dp[N][1][0],
                              dp[N][0][1],
                              dp[N][1][1] + B[N - 1]
                      });
    cout << ans << endl;

    return 0;
}