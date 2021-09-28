#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <queue>
#include <stack>

using namespace std;
using ll = long long int;
using pll = pair<ll, ll>;

#define FOR(i, n, m) for(ll i = (m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

int main() {
    ll N;
    cin >> N;
    string S;
    cin >> S;
    vector<vector<ll>> dp(N + 5, vector<ll>(N + 5, 0));
    for (ll i = N - 1; i >= 0; --i) {
        for (ll j = i + 1; j < N; ++j) {
            if (S[i] != S[j])
                continue;
            if (j + 1 < N && S[i + 1] == S[j + 1]) {
                ll len = std::min(dp[i + 1][j + 1], j - (i + 1));
                dp[i][j] = std::max(dp[i][j], 1 + len);
            } else {
                dp[i][j] = 1;
            }
        }
    }

    ll ans = 0;
    REP(i, N) {
        REP(j, N) {
            ans = std::max(ans, dp[i][j]);
        }
    }
    cout << ans << endl;
    return 0;
}