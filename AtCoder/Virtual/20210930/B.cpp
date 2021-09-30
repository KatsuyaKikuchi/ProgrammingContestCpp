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

ll dp[1005][1005];

int main() {
    ll N, M;
    cin >> N >> M;
    vector<ll> A(N), B(M);
    REP(i, N) {
        cin >> A[i];
    }
    REP(i, M) {
        cin >> B[i];
    }
    REP(i, N + 1) {
        REP(j, M + 1) {
            dp[i][j] = INF;
        }
    }
    REP(i, N + 1) {
        dp[i][0] = i;
    }
    REP(j, M + 1) {
        dp[0][j] = j;
    }

    REP(i, N) {
        REP(j, M) {
            dp[i + 1][j + 1] = std::min({dp[i][j], dp[i + 1][j], dp[i][j + 1]}) + 1;
            if (A[i] == B[j])
                dp[i + 1][j + 1] = std::min(dp[i + 1][j + 1], dp[i][j]);
        }
    }

    cout << dp[N][M] << endl;
    return 0;
}