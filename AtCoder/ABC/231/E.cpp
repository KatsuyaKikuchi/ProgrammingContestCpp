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
const ll INF = (ll) 1e18 + 5;
const long double PI = 3.1415926535897932384626433832795028841971;

ll solve(vector<ll> &V, vector<ll> &A) {
    ll ret = 0;
    ll N = A.size();
    vector<vector<ll>> dp(N + 1, vector<ll>(2, INF));
    dp[0][0] = 0;
    REP(i, N - 1) {
        dp[i + 1][0] = std::min(dp[i][0] + V[i], dp[i][1] + V[i] + 1);
        ll p = A[i + 1] / A[i];
        dp[i + 1][1] = std::min(dp[i][0] + p - V[i], dp[i][1] + p - (V[i] + 1));
    }
    return std::min(dp[N - 1][0], dp[N - 1][1]);
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, X;
    cin >> N >> X;
    vector<ll> A(N);
    REP(i, N) {
        cin >> A[i];
    }

    vector<ll> V(N, 0);
    ll x = X;
    for (ll i = N - 1; i >= 0; --i) {
        V[i] = x / A[i];
        x = x % A[i];
    }
    ll ans = 0;
    REP(i, N) {
        ans += V[i];
    }

    REP(i, N - 1) {
        V[i + 1]++;
        V[i] = 0;
        ll s = 0;
        ll sum = 0;
        REP(j, N) {
            s += A[j] * V[j];
            sum += V[j];
        }
        ll t = s - X;
        vector<ll> v(N, 0);
        for (ll j = N - 1; j >= 0; --j) {
            v[j] = t / A[j];
            t = t % A[j];
        }
        ans = std::min(ans, sum + solve(v, A));
    }
    cout << ans << endl;
    return 0;
}