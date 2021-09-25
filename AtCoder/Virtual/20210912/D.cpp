#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
using ll = long long int;
using pll = pair<ll, ll>;

#define FOR(i, n, m) for(ll i = (m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)

const ll INF = (ll) 1e15;
const ll MOD = 998244353;

ll dp[200005];

int main() {
    ll N, K;
    cin >> N >> K;
    vector<pll> R(K);
    REP(i, K) {
        cin >> R[i].first >> R[i].second;
    }
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    dp[1] = MOD - 1;
    FOR(i, N + 1, 0) {
        if (i > 0)
            dp[i] = (dp[i] + dp[i - 1]) % MOD;
        REP(j, K) {
            ll min = std::min(N, i + R[j].first);
            ll max = std::min(N, i + R[j].second) + 1;
            dp[min] += dp[i];
            dp[max] += (MOD - dp[i]) % MOD;

            dp[min] %= MOD;
            dp[max] %= MOD;
        }
    }

    cout << dp[N - 1] << endl;

    return 0;
}