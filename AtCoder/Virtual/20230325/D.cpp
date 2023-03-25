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

template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val) {
    std::fill((T *) array, (T *) (array + N), val);
}

ll dp[3005][3005][5];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll R, C, K;
    cin >> R >> C >> K;
    vector<vector<ll>> A(R, vector<ll>(C, 0));
    REP(i, K) {
        ll r, c, v;
        cin >> r >> c >> v;
        r--;
        c--;
        A[r][c] = v;
    }

    Fill(dp, -INF);
    REP(i, R + 1) {
        dp[i][0][0] = 0;
    }
    REP(i, C + 1) {
        dp[0][i][0] = 0;
    }
    REP(i, R) {
        REP(j, C) {
            REP(k, 4) {
                dp[i + 1][j + 1][k] = std::max(dp[i + 1][j + 1][k], dp[i + 1][j][k]);
                dp[i + 1][j + 1][0] = std::max(dp[i + 1][j + 1][0], dp[i][j + 1][k]);
            }
            for (int k = 2; k >= 0; --k) {
                dp[i + 1][j + 1][k + 1] = std::max(dp[i + 1][j + 1][k + 1], dp[i + 1][j + 1][k] + A[i][j]);
            }
        }
    }

    ll ans = 0;
    REP(i, 5) {
        ans = std::max(ans, dp[R][C][i]);
    }
    cout << ans <<endl;

    return 0;
}