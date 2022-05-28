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

void solve() {
    ll N, K;
    cin >> N >> K;
    ll diff = N * N - 1 - K;
    ll start = 1;
    ll s = N - 1;
    vector<vector<pll>> V;
    for (ll i = 1; i <= N / 2; ++i) {
        // i週目で近道する

        ll nxtStart = start + 2LL * ((N - 2 * i) + (N - 2 * (i - 1)));
        vector<pll> d(4);
        REP(j, 4) {
            d[j] = pll(start + 1 + s * j, nxtStart - (start + 1) - 2 * j - 1);
        }
        start = nxtStart;
        s -= 2;
        V.push_back(d);
    }

    vector<pll> ans;
    REP(i, V.size()) {
        REP(j, V[i].size()) {
            if (diff >= V[i][j].second && V[i][j].second != 0) {
                diff -= V[i][j].second;
                ans.emplace_back(V[i][j].first, V[i][j].first + V[i][j].second + 1);
                break;
            }
        }
    }

    if (diff != 0) {
        cout << "IMPOSSIBLE" << endl;
        return;
    }

    cout << ans.size() << endl;
    REP(i, ans.size()) {
        cout << ans[i].first << " " << ans[i].second << endl;
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll T;
    cin >> T;
    REP(i, T) {
        cout << "Case #" << i + 1 << ": ";
        solve();
    }
    return 0;
}