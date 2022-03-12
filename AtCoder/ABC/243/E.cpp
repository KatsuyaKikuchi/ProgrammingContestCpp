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

struct Edge {
    ll a, b, c;
};
struct Vertex {
    vector<pll> node;
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, M;
    cin >> N >> M;
    vector<Edge> E(M);
    vector<vector<ll>> D(N, vector<ll>(N, INF));
    REP(i, N) {
        D[i][i] = 0;
    }
    REP(i, M) {
        cin >> E[i].a >> E[i].b >> E[i].c;
        E[i].a--;
        E[i].b--;
        D[E[i].a][E[i].b] = D[E[i].b][E[i].a] = std::min(D[E[i].a][E[i].b], E[i].c);
    }
    REP(k, N) {
        REP(i, N) {
            REP(j, N) {
                D[i][j] = std::min(D[i][j], D[i][k] + D[k][j]);
            }
        }
    }
    sort(E.begin(), E.end(), [](Edge a, Edge b) { return a.c < b.c; });
    vector<Vertex> V(N);
    vector<Edge> tmp;
    ll ans = 0;
    for (auto &e: E) {
        ll a = e.a, b = e.b, c = e.c;
        if (D[a][b] < c) {
            ans++;
            continue;
        }
#if false
        priority_queue<pll, vector<pll>, function<bool(pll, pll)>> q([](pll a, pll b) { return a.second > b.second; });
        q.push(pll(a, 0));
        vector<ll> d(N, INF);
        d[a] = 0;
        while (!q.empty()) {
            auto t = q.top();
            q.pop();
            if (t.first == b)
                break;
            if (d[t.first] < t.second)
                continue;
            for (auto &n: V[t.first].node) {
                ll nxt = n.first;
                ll cost = n.second + t.second;
                if (d[nxt] <= cost)
                    continue;
                d[nxt] = cost;
                q.push(pll(nxt, cost));
            }
        }

        if (d[b] > D[a][b]) {
            V[a].node.emplace_back(b, c);
            V[b].node.emplace_back(a, c);
        } else {
            ans++;
        }
#else
        bool ex = true;
        for (auto n: V[a].node) {
            ll t = n.first;
            if (D[a][t] + D[t][b] == c)ex = false;
        }
        if (ex) {
            V[a].node.emplace_back(b, c);
            V[b].node.emplace_back(a, c);
        } else {
            ans++;
        }
#endif
    }

    cout << ans << endl;
    return 0;
}