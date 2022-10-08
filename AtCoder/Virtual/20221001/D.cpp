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
    ll N, M;
    cin >> N >> M;
    vector<ll> X(N);
    REP(i, N) {
        cin >> X[i];
    }
    vector<ll> C(N + 5, 0);
    REP(i, M) {
        ll c, y;
        cin >> c >> y;
        C[c] = y;
    }

    vector<vector<ll>> dp(N + 5, vector<ll>(N + 5, 0));
    REP(i, N) {
        REP(j, i + 1) {
            dp[i + 1][j + 1] = std::max(dp[i + 1][j + 1], dp[i][j] + X[i] + C[j + 1]);
            dp[i + 1][0] = std::max(dp[i + 1][0], dp[i][j]);
        }
    }
    ll ans = 0;
    REP(i, N + 1) {
        ans = std::max(ans, dp[N][i]);
    }
    cout << ans << endl;
    return 0;
}