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

struct Edge {
    ll a, b;
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, M, E;
    cin >> N >> M >> E;
    vector<Edge> edge(E);
    REP(i, E) {
        cin >> edge[i].a >> edge[i].b;
        edge[i].a--;
        edge[i].b--;
    }
    ll Q;
    cin >> Q;
    vector<bool> cut(E, false);
    vector<ll> query(Q);
    REP(i, Q) {
        cin >> query[i];
        query[i]--;
        cut[query[i]] = true;
    }

    dsu enable(N + 1);
    REP(i, E) {
        if (cut[i])
            continue;
        ll a = std::min(edge[i].a, N);
        ll b = std::min(edge[i].b, N);
        enable.merge(a, b);
    }

    ll count = 0;
    REP(i, N) {
        if (enable.same(N, i))
            count++;
    }

    vector<ll> ans(Q);
    REP(i, Q) {
        ans[Q - 1 - i] = count;
        Edge e = edge[query[Q - 1 - i]];

        ll a = std::min(e.a, N);
        ll b = std::min(e.b, N);

        if (!enable.same(N, a)) {
            if (enable.same(N, b)) {
                count += enable.size(a);
            }
        } else if (!enable.same(N, b)) {
            count += enable.size(b);
        }
        enable.merge(a, b);
    }

    REP(i, Q) {
        cout << ans[i] << endl;
    }

    return 0;
}