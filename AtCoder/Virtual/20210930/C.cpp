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
    string S;
    cin >> S;

    ll N = S.length();
    vector<vector<ll>> dp(N + 5, vector<ll>(2, 0));
    dp[0][0] = 1;
    REP(i, N) {
        if (S[i] == '0') {
            {
                // 0
                dp[i + 1][1] += dp[i][1];
                dp[i + 1][0] += dp[i][0];
            }
            {
                // 1
                dp[i + 1][1] += dp[i][1] * 2LL;
            }
        } else {
            {
                // 0
                dp[i + 1][1] += dp[i][0];
                dp[i + 1][1] += dp[i][1];
            }
            {
                // 1
                dp[i + 1][1] += dp[i][1] * 2LL;
                dp[i + 1][0] += dp[i][0] * 2LL;
            }
        }
        dp[i + 1][0] %= MOD;
        dp[i + 1][1] %= MOD;
    }

    ll ans = dp[N][0] + dp[N][1];
    cout << ans % MOD << endl;
    return 0;
}