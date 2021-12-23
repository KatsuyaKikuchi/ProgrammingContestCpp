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
    ll N, M;
    cin >> N >> M;
    vector<pll> A(M, pll(0, 0));
    REP(i, M) {
        string s;
        cin >> s >> A[i].second;
        REP(j, N) {
            if (s[j] == 'Y')
                A[i].first |= (1LL << j);
        }
    }

    ll p = pow(2LL, N);
    vector<ll> dp(p, INF);
    dp[0] = 0;
    REP(bit, p) {
        REP(i, M) {
            ll nxt = (bit | A[i].first);
            dp[nxt] = std::min(dp[bit] + A[i].second, dp[nxt]);
        }
    }

    ll ans = dp[p - 1];
    if (ans == INF)
        ans = -1;
    cout << ans << endl;
    return 0;
}