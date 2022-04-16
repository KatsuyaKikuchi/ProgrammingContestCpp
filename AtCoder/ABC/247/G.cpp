#include <bits/stdc++.h>
#include "../../atcoder/all"

using namespace std;
using namespace atcoder;
using ll = long long int;
using pll = pair<ll, ll>;

#define FOR(i, n, m) for(ll i = (m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;
const ll MAX = 150;
const long double PI = 3.1415926535897932384626433832795028841971;

struct Data {
    ll a, b, c;
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    vector<Data> D(N);
    REP(i, N) {
        cin >> D[i].a >> D[i].b >> D[i].c;
        D[i].a--;
        D[i].b--;
    }

    vector<ll> ans;
    REP(i, N) {
        mcf_graph<ll, ll> graph(2 + MAX * 2);
        REP(j, MAX) {
            graph.add_edge(0, j + 2, 1, 0);
            graph.add_edge(j + 2 + MAX, 1, 1, 0);
        }
        REP(j, N) {
            graph.add_edge(D[j].a + 2, D[j].b + 2 + MAX, 1, INF - D[j].c);
        }

        pll cost = graph.flow(0, 1, i + 1);
        if (cost.first != i + 1)
            break;
        ans.push_back(INF * (i + 1) - cost.second);
    }

    cout << ans.size() << endl;
    REP(i, ans.size()) {
        cout << ans[i] << endl;
    }
    return 0;
}