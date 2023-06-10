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
    vector<ll> dp(N + 5, INF);
    REP(i, N + 1) {
        dp[i] = i;
    }
    {
        ll n = 9;
        while (n <= N) {
            REP(i, 9) {
                REP(j, N) {
                    if (j + i * n > N)
                        break;
                    dp[j + i * n] = std::min(dp[j + i * n], dp[j] + i);
                }
            }
            n *= 9;
        }
    }
    {
        ll n = 6;
        while (n <= N) {
            REP(i, 6) {
                REP(j, N) {
                    if (j + i * n > N)
                        break;
                    dp[j + i * n] = std::min(dp[j + i * n], dp[j] + i);
                }
            }
            n *= 6;
        }
    }
    cout << dp[N] << endl;
    return 0;
}