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
    ll N, X;
    cin >> N >> X;
    vector<vector<ll>> A(N);
    REP(i, N) {
        ll k;
        cin >> k;
        REP(j, k) {
            ll a;
            cin >> a;
            A[i].push_back(a);
        }
    }
    vector<ll> dp;
    dp.push_back(X);
    REP(i, N) {
        vector<ll> t;
        REP(k, dp.size()) {
            REP(j, A[i].size()) {
                if (dp[k] % A[i][j] == 0)
                    t.push_back(dp[k] / A[i][j]);
            }
        }
        swap(dp, t);
    }

    ll ans = 0;
    REP(i, dp.size()) {
        if (dp[i] == 1)
            ans++;
    }
    cout << ans << endl;
    return 0;
}