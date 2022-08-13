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

ll dp[2010][2010][2][2];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll H, W;
    cin >> H >> W;
    vector<ll> R(H);
    vector<ll> C(W);
    REP(i, H) {
        cin >> R[i];
    }
    REP(i, W) {
        cin >> C[i];
    }
    vector<string> S(H);
    REP(i, H) {
        cin >> S[i];
    }

    ll ans = INF;
    REP(i, H + 5) {
        REP(j, W + 5) {
            REP(a, 2) {
                REP(b, 2) {
                    dp[i][j][a][b] = INF;
                }
            }
        }
    }

    dp[0][0][0][0] = 0;
    dp[0][0][0][1] = C[0];
    dp[0][0][1][0] = R[0];
    REP(i, H) {
        REP(j, W) {
            REP(a, 2) {
                REP(b, 2) {

                    ll color = (S[i][j] - '0' + a + b) % 2;
                    if (j + 1 < W) {
                        // 横に移動
                        ll nxtColor = (S[i][j + 1] + a - '0') % 2;
                        if (color == nxtColor) {
                            dp[i][j + 1][a][0] = std::min(dp[i][j + 1][a][0], dp[i][j][a][b]);

                        } else {
                            dp[i][j + 1][a][1] = std::min(dp[i][j + 1][a][1], dp[i][j][a][b] + C[j + 1]);
                            if (b == 0 && j == 0) {
                                dp[i][j + 1][a][0] = std::min(dp[i][j + 1][a][0], dp[i][j][a][b] + C[j]);
                            }
                        }
                    }
                    if (i + 1 < H) {
                        // 下に移動
                        ll nxtColor = (S[i + 1][j] + b - '0') % 2;
                        if (color == nxtColor) {
                            dp[i + 1][j][0][b] = std::min(dp[i + 1][j][0][b], dp[i][j][a][b]);
                        } else {
                            dp[i + 1][j][1][b] = std::min(dp[i + 1][j][1][b], dp[i][j][a][b] + R[i + 1]);
                            if (a == 0 && i == 0) {
                                dp[i + 1][j][0][b] = std::min(dp[i + 1][j][0][b], dp[i][j][a][b] + R[i]);
                            }
                        }
                    }
                }
            }
        }
    }

    REP(i, 2) {
        REP(j, 2) {
            ans = std::min(ans, dp[H - 1][W - 1][i][j]);
        }
    }
    cout << ans << endl;
    return 0;
}