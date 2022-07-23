#include <bits/stdc++.h>
#include "atcoder/all"

using namespace atcoder;
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
    ll N;
    cin >> N;
    vector<ll> X(N), C(N);

    scc_graph g(N);

    REP(i, N) {
        cin >> X[i];
        X[i]--;
        g.add_edge(i, X[i]);
    }
    REP(i, N) {
        cin >> C[i];
    }

    ll ans = 0;
    auto scc = g.scc();
    for (auto v: scc) {
        if (v.size() == 1)
            continue;
        ll m = INF;
        for (auto n: v) {
            m = std::min(C[n], m);
        }
        if (m == INF)
            continue;
        ans += m;
    }
    cout << ans << endl;
    return 0;
}