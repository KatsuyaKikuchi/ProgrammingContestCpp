#include <bits/stdc++.h>
#include "atcoder/all"

using namespace std;
using namespace atcoder;
using ll = long long int;
using pll = pair<ll, ll>;

#define FOR(i, n, m) for(ll i = (m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e17;
const long double PI = 3.1415926535897932384626433832795028841971;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, M;
    cin >> N >> M;

    mf_graph<ll> graph(N * 2);

    REP(_, M) {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        graph.add_edge(a + N, b, INF);
        graph.add_edge(b + N, a, INF);
    }
    vector<ll> C(N);
    REP(i, N) {
        cin >> C[i];
    }

    FOR(i, N - 1, 1) {
        graph.add_edge(i, i + N, C[i]);
    }
    graph.add_edge(0, 0 + N, INF);
    graph.add_edge(N - 1, N - 1 + N, INF);
    ll s = 0, g = 2 * N - 1;

    ll sum = graph.flow(s, g);

    auto x = graph.min_cut(s);
    vector<ll> ans;

    FOR(i, N - 1, 1) {
        if (x[i] && !x[i + N])
            ans.push_back(i + 1);
    }
    cout << sum << endl;
    cout << ans.size() << endl;
    REP(i, ans.size()) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}