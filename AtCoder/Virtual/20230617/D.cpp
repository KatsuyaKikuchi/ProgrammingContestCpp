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
    string S;
    cin >> S;
    ll dp[2] = {0, 1};
    REP(i, S.size()) {
        ll tmp[2] = {INF, INF};
        ll n = S[i] - '0';
        tmp[0] = std::min({n + dp[0], tmp[0], dp[1] + std::max((10 - n) % 10, 1LL)});
        tmp[1] = std::min({tmp[1], dp[0] + n + 1, dp[1] + (9 - n)});

        swap(dp, tmp);
    }
    cout << std::min(dp[0], dp[1] + 1) << endl;
    return 0;
}