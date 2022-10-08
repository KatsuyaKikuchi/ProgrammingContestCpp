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

    vector<double> dp(N + 5, 0);
    dp[N] = 3.5;

    for (ll i = N - 1; i >= 0; --i) {
        double p = dp[i + 1];
        REP(j, 6) {
            if (p <= j + 1)
                dp[i] += (j + 1) / 6.0;
            else
                dp[i] += p / 6.0;
        }
    }

    cout << OF64 << dp[1] << endl;
    return 0;
}