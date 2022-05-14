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
    ll N;
    cin >> N;
    vector<ll> A(N);
    REP(i, N) {
        cin >> A[i];
    }
    ll ans = INF;
    {
        // A1
        vector<ll> dp(N + 5, INF);
        dp[1] = dp[2] = A[0];
        FOR(i, N, 1) {
            dp[i + 1] = std::min({dp[i + 1],
                                  dp[i - 1] + A[i - 1],
                                  dp[i] + A[i]});
        }
        ans = std::min({ans, dp[N], dp[N + 1]});
    }
    {
        // AN
        vector<ll> dp(N + 5, INF);
        dp[1] = A[N - 1];
        FOR(i, N - 1, 1) {
            dp[i + 1] = std::min({dp[i + 1],
                                  dp[i - 1] + A[i - 1],
                                  dp[i] + A[i]});
        }
        ans = std::min({ans, dp[N - 1], dp[N]});
    }
    cout << ans << endl;

    return 0;
}