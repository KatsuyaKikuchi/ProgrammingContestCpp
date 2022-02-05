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

struct Vertex {
    vector<pll> node;
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, M;
    cin >> N >> M;
    vector<Vertex> V(N);
    REP(_, M) {
        ll a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        V[a].node.push_back(pll(b, c));
    }
    REP(i, N - 1) {
        V[i + 1].node.push_back(pll(i, 0));
    }

    vector<ll> D(N, INF);
    D[0] = 0;
    priority_queue<pll, vector<pll>, function<bool(pll, pll)>> q([](pll a, pll b) { return a.second > b.second; });
    q.push(pll(0, 0));
    while (!q.empty()) {
        pll t = q.top();
        q.pop();
        if (D[t.first] < t.second)
            continue;
        for (auto n: V[t.first].node) {
            ll nxt = n.first;
            ll cost = n.second + t.second;
            if (D[nxt] <= cost)
                continue;
            D[nxt] = cost;
            q.push(pll(nxt, cost));
        }
    }

    ll ans = D[N - 1];
    if (ans == INF)
        ans = -1;
    cout << ans << endl;
    return 0;
}