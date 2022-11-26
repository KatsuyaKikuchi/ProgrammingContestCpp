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

vector<ll> calc(ll n) {
    vector<ll> ret;
    vector<ll> v;
    while (n > 0) {
        v.push_back(n % 10);
        n /= 10;
    }
    sort(v.begin(), v.end());
    do {
        ll x = 0;
        for (auto t: v) {
            x = x * 10LL + t;
        }
        ret.push_back(x);
    } while (next_permutation(v.begin(), v.end()));
    return ret;
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
    ll MAX = 10000;

    vector<vector<ll>> nxt;
    REP(i, MAX) {
        auto v = calc(i);
        nxt.push_back(v);
    }

    vector<vector<ll>> dp(N + 5, vector<ll>(MAX, -INF));
    dp[0][X] = 0;
    REP(i, N) {
        REP(n, MAX) {
            for (auto x: nxt[n]) {
                dp[i + 1][x] = std::max(dp[i + 1][x], dp[i][n]);
                ll t = x - A[i];
                if (t < 0)
                    continue;
                dp[i + 1][t] = std::max(dp[i + 1][t], dp[i][n] + 1);
            }
        }
    }

    ll ans = 0;
    REP(i, N) {
        REP(n, MAX) {
            ans = std::max(ans, dp[i + 1][n]);
        }
    }
    cout << ans << endl;
    return 0;
}