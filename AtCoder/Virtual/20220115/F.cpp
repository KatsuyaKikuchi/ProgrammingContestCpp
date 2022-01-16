#include <bits/stdc++.h>

using namespace std;
using ll = long long int;
using pll = pair<ll, ll>;

#define FOR(i, n, m) for(ll i = (m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e18 + 100;
const long double PI = 3.1415926535897932384626433832795028841971;

// [iまでの中から][n個選んで][mod mが][xになるもの]=の最大値
ll dp[105][105][105][105];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, X;
    cin >> N >> X;
    vector<ll> A(N);
    REP(i, N) {
        cin >> A[i];
    }

    memset(dp, -1, sizeof(dp));
    FOR(i, N + 1, 1) {
        dp[0][0][i][0] = 0;
    }
    ll ans = INF;
    REP(i, N) {
        REP(n, N + 1) {
            FOR(m, N + 1, 1) {
                REP(x, N + 1) {
                    dp[i + 1][n][m][x] = std::max(dp[i][n][m][x], dp[i + 1][n][m][x]);
                    if (dp[i][n][m][x] < 0)
                        continue;
                    ll s = dp[i][n][m][x] + A[i];
                    dp[i + 1][n + 1][m][s % m] = std::max(dp[i + 1][n + 1][m][s % m], s);

                    if ((X - s) % (n + 1) == 0) {
                        ans = std::min(ans, (X - s) / (n + 1));
                    }
                }
            }
        }
    }

    cout << ans << endl;

    return 0;
}