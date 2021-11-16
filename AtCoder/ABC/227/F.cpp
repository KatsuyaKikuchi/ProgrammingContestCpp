#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <queue>
#include <stack>
#include <iomanip>
#include <cmath>
#include <map>
#include <set>

using namespace std;
using ll = long long int;
using pll = pair<ll, ll>;

#define FOR(i, n, m) for(ll i = (m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;
const long double PI = 3.1415926535897932384626433832795028841971;

ll H, W, K;
vector<vector<ll>> A;

ll solve(ll mx) {
    vector<vector<ll>> M(H);
    REP(i, H) {
        REP(j, W) {
            if (A[i][j] <= mx)
                M[i].push_back(0);
            else
                M[i].push_back(A[i][j]);
        }
    }

    ll max = H + W + 10;
    vector<vector<vector<ll>>> dp(H + 5, vector<vector<ll>>(W + 5, vector<ll>(max, INF)));
    if (M[0][0] == 0)
        dp[0][0][0] = 0;
    else
        dp[0][0][1] = M[0][0];

    REP(i, H) {
        REP(j, W) {
            REP(k, max - 1) {
                if (i + 1 < H) {
                    if (M[i + 1][j] == 0)
                        dp[i + 1][j][k] = std::min(dp[i + 1][j][k], dp[i][j][k]);
                    else
                        dp[i + 1][j][k + 1] = std::min(dp[i + 1][j][k + 1], dp[i][j][k] + M[i + 1][j]);
                }

                if (j + 1 < W) {
                    if (M[i][j + 1] == 0)
                        dp[i][j + 1][k] = std::min(dp[i][j + 1][k], dp[i][j][k]);
                    else
                        dp[i][j + 1][k + 1] = std::min(dp[i][j + 1][k + 1], dp[i][j][k] + M[i][j + 1]);
                }
            }
        }
    }

    ll ret = INF;
    REP(i, max) {
        ret = std::min(dp[H - 1][W - 1][i] + mx * std::max(0LL, (K - i)), ret);
    }
    return ret;

}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> H >> W >> K;
    A.resize(H);
    REP(i, H) {
        A[i].resize(W);
    }
    vector<ll> v;
    REP(i, H) {
        REP(j, W) {
            cin >> A[i][j];
            v.push_back(A[i][j]);
        }
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());

    ll ans = INF;
    REP(i, v.size()) {
        ans = std::min(ans, solve(v[i]));
    }

    cout << ans << endl;
    return 0;
}