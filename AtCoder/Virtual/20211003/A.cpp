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

ll dp[55][5];

int main() {
    ll N, P;
    cin >> N >> P;
    vector<ll> A(N);
    REP(i, N) {
        cin >> A[i];
    }
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    REP(i, N) {
        REP(j, 2) {
            ll n = (j + A[i]) % 2;
            dp[i + 1][n] += dp[i][j];
            dp[i + 1][j] += dp[i][j];
        }
    }

    cout << dp[N][P] << endl;
    return 0;
}