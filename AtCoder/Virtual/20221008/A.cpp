#include <bits/stdc++.h>

using namespace std;
using ll = long long int;
using pll = pair<ll, ll>;

#define FOR(i, n, m) for(ll i = (m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e5;
const long double PI = 3.1415926535897932384626433832795028841971;

ll N;
vector<ll> X;
ll S;

bool check(ll m) {
    vector<bool> dp(INF + 5, false);
    dp[0] = true;
    REP(i, N) {
        vector<bool> tmp(INF + 5, false);
        REP(j, dp.size()) {
            if (!dp[j])
                continue;
            tmp[j] = true;
            if (j + X[i] > S)
                continue;
            tmp[j + X[i]] = true;
        }
        swap(tmp, dp);
    }

    REP(s, S + 1) {
        if (!dp[s])
            continue;
        ll t = std::max(s, S - s);
        if (t <= m)
            return true;
    }
    return false;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> N;
    X.resize(N);
    S = 0;
    REP(i, N) {
        cin >> X[i];
        S += X[i];
    }
    ll ans = INF + 10, ng = -1;
    while (abs(ans - ng) > 1) {
        ll mid = (ans + ng) / 2;
        if (check(mid))
            ans = mid;
        else
            ng = mid;
    }
    cout << ans << endl;
    return 0;
}