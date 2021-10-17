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
    string S;
    cin >> S;
    string s = "atcoder";
    vector<vector<ll> > dp(N + 5, vector<ll>(s.length() + 5, 0));
    dp[0][0] = 1;
    REP(i, N) {
        REP(j, s.length() + 1) {
            dp[i + 1][j] += dp[i][j];
            if (s.length() == j || s[j] != S[i])
                continue;
            dp[i + 1][j + 1] += dp[i][j];
        }
        REP(j, s.length() + 1) {
            dp[i + 1][j] %= MOD;
        }
    }
    cout << dp[N][s.length()] << endl;
    return 0;
}