#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <queue>
#include <stack>
#include <iomanip>
#include <cmath>
#include <map>
#include <set>

using namespace std;
using ll = long long int;
using pll = pair<ll, ll>;

#define FOR(i, n, m) for(ll i = (m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

struct Data {
    ll d, c, s;
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    vector<Data> D(N);
    REP(i, N) {
        cin >> D[i].d >> D[i].c >> D[i].s;
    }
    sort(D.begin(), D.end(), [](Data a, Data b) { return a.d < b.d; });
    vector<ll> dp(5015, 0);
    REP(i, N) {
        for (ll j = 5005; j >= 0; --j) {
            if (D[i].d < j)
                continue;
            if (j - D[i].c < 0)
                break;
            dp[j] = std::max(dp[j], dp[j - D[i].c] + D[i].s);
        }
        REP(j, 5005) {
            dp[j + 1] = std::max(dp[j + 1], dp[j]);
        }
    }

    ll ans = 0;
    REP(i, dp.size()) {
        ans = std::max(ans, dp[i]);
    }
    cout << ans << endl;
    return 0;
}