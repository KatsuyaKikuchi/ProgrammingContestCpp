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

int main() {
    ll N;
    cin >> N;
    vector<ll> C(N);
    REP(i, N) {
        cin >> C[i];
        C[i]--;
    }
    vector<ll> P(200005, -1);
    vector<ll> dp(N + 5, 0);
    dp[0] = 1;
    REP(i, N) {
        dp[i + 1] = dp[i];
        if (P[C[i]] >= 0 && P[C[i]] != i) {
            dp[i + 1] += dp[P[C[i]]];
            dp[i + 1] %= MOD;
        }
        P[C[i]] = i + 1;
    }
    cout << dp[N] << endl;
    return 0;
}