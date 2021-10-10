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
    ll N, K;
    cin >> N >> K;
    vector<pll> A(N);
    REP(i, N) {
        cin >> A[i].first >> A[i].second;
    }
    vector<ll> v;
    ll k = K;
    while (k > 0) {
        v.push_back(k % 2);
        k /= 2;
    }
    reverse(v.begin(), v.end());
    vector<vector<ll>> dp(v.size() + 5, vector<ll>(2, 0));
    REP(i, N) {
        ll n = 0;
        REP(j, v.size()) {
            if()
            if (v[j] == 1) {
                if ((n | A[i].first) <= K) {
                    dp[j + 1][1] = std::max(dp[j + 1][1], dp[j][0] + A[i].second);
                }
            } else {

            }
        }
    }
    ll ans = 0;
    REP(i, dp.size()) {
        ans = std::max({ans, dp[i][0], dp[i][1]});
    }
    cout << ans << endl;
    return 0;
}