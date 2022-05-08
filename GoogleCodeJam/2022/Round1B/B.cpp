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

ll solve() {
    ll N, P;
    cin >> N >> P;
    vector<vector<ll> > A(N + 1, vector<ll>(P, 0));
    REP(i, N) {
        REP(j, P) {
            cin >> A[i + 1][j];
        }
        sort(A[i + 1].begin(), A[i + 1].end());
    }

    vector<ll> dp(2, 0);
    REP(i, N) {
        vector<ll> tmp(2, INF);
        ll L = A[i + 1][0];
        ll R = A[i + 1][P - 1];
        {
            ll left = A[i][0];
            tmp[0] = std::min(tmp[0], abs(left - R) + R - L + dp[0]);
            tmp[1] = std::min(tmp[1], abs(left - L) + R - L + dp[0]);
        }
        {
            ll right = A[i][P - 1];
            tmp[0] = std::min(tmp[0], abs(right - R) + R - L + dp[1]);
            tmp[1] = std::min(tmp[1], abs(right - L) + R - L + dp[1]);
        }
        swap(dp, tmp);
    }
    return std::min(dp[0], dp[1]);
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll T;
    cin >> T;
    REP(i, T) {
        cout << "Case #" << i + 1 << ": " << solve() << endl;
    }
    return 0;
}