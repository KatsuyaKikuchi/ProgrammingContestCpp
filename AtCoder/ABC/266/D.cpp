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

struct Data {
    ll T;
    ll X;
    ll A;
};

ll dp[100005][15];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    vector<Data> D(N);
    REP(i, N) {
        cin >> D[i].T >> D[i].X >> D[i].A;
    }
    memset(dp, 0, sizeof(dp));
    REP(i, 15) {
        dp[0][i] = -INF;
    }
    dp[0][0] = 0;

    ll M = 100002;
    ll index = 0;
    REP(i, M) {
        ll t = i + 1;
        pll x(-1, -INF);
        if (index < N && t == D[index].T) {
            x = pll(D[index].X, D[index].A);
            index++;
        }
        REP(j, 5) {
            ll value = 0;
            if (j == x.first)
                value = x.second;

            dp[t][j] = dp[i][j] + value;
            if (j > 0)
                dp[t][j] = std::max(dp[t][j], dp[i][j - 1] + value);
            if (j < 4)
                dp[t][j] = std::max(dp[t][j], dp[i][j + 1] + value);
        }
    }

    ll ans = 0;
    REP(i, 5) {
        ans = std::max(ans, dp[M][i]);
    }
    cout << ans << endl;

    return 0;
}