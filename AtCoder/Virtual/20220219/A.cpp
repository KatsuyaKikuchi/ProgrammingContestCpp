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

ll check(string s, string t) {
    vector<ll> dp(t.size(), 0);
    REP(i, s.size()) {
        ll mx = 0;
        for (ll j = t.size() - 1; j >= 0; --j) {
            ll mx = 0;
            REP(k, j) {
                mx = std::max(dp[k], mx);
            }
            if (s[i] == t[j])mx++;
            dp[j] = std::max(mx, dp[j]);
        }
    }

    ll ret = 0;
    REP(i, dp.size()) {
        ret = std::max(ret, dp[i]);
    }
    return ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    string S;
    cin >> S;
    ll ans = N;
    REP(i, N) {
        string s = S.substr(0, i);
        string t = S.substr(i);
        ll len = check(s, t);
        ans = std::min(ans, N - len * 2);
    }

    cout << ans << endl;

    return 0;
}