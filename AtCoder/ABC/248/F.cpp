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

ll dp[3005][3005][2];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll N, P;
    cin >> N >> P;
    memset(dp, 0, sizeof(dp));
    // 0:連結, 1:非連結
    dp[1][0][0] = 1;
    dp[1][1][1] = 1;

    FOR(i, N, 1) {
        REP(j, N) {
            {
                dp[i + 1][j][0] += dp[i][j][0] + dp[i][j][1];
                dp[i + 1][j + 1][0] += dp[i][j][0] * 3LL;
            }
            {
                dp[i + 1][j + 2][1] += dp[i][j][0] * 2LL;
                dp[i + 1][j + 1][1] += dp[i][j][1];
            }
            dp[i + 1][j][0] %= P;
            dp[i + 1][j + 1][1] %= P;
            dp[i + 1][j + 1][0] %= P;
            dp[i + 1][j + 2][1] %= P;

        }
    }

#if false
    REP(i, N) {
        cout << "ren:";
        REP(j, N) {
            cout << dp[i + 1][j][0] << " ";
        }
        cout << endl;
        cout << "not:";
        REP(j, N) {
            cout << dp[i + 1][j][1] << " ";
        }
        cout << endl;
    }
#endif

    FOR(i, N, 1) {
        cout << dp[N][i][0] << " ";
    }
    cout << endl;

    return 0;
}