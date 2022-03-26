#include <bits/stdc++.h>
#include "../../atcoder/all"

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

struct Vertex {
    vector<ll> to;
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, M;
    cin >> N >> M;
    scc_graph G(N);
    dsu uf(N);
    vector<Vertex> T(N);
    REP(_, M) {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        G.add_edge(a, b);
        T[a].to.push_back(b);
    }
    vector<bool> C(N, false);
    auto V = G.scc();
    ll ans = 0;
    for (ll i = V.size() - 1; i >= 0; --i) {
        auto &v = V[i];
        ll n = v.size();
        if (n == 1) {
            bool cycle = false;
            REP(j, T[v[0]].to.size()) {
                ll x = T[v[0]].to[j];
                if (C[x]) {
                    cycle = true;
                    ans++;
                    break;
                }
            }
            C[v[0]] = cycle;
            continue;
        }
        ans += n;
        REP(j, n - 1) {
            uf.merge(v[j], v[j + 1]);
        }
        REP(j, n) {
            C[v[j]] = true;
        }
    }
    cout << ans << endl;
    return 0;
}