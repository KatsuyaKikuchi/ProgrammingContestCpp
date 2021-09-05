#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <functional>

using namespace std;
using ll = long long int;
using pll = pair<ll, ll>;

#define FOR(i, n, m) for(ll i = (m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)

const ll INF = (ll) 1e15;

struct Data {
    ll n, t, k;
};
struct Vertex {
    vector<Data> node;
};

Vertex V[100005];

int main() {
    ll N, M, X, Y;
    cin >> N >> M >> X >> Y;
    X--;
    Y--;
    REP(i, M) {
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        a--;
        b--;
        V[a].node.push_back(Data{b, c, d});
        V[b].node.push_back(Data{a, c, d});
    }

    vector<ll> C(N, INF);
    priority_queue<pll, vector<pll>, function<bool(pll, pll)>> q([](pll a, pll b) { return a.second > b.second; });
    q.push(pll(X, 0));
    while (!q.empty()) {
        auto d = q.top();
        q.pop();
        if (C[d.first] < d.second)continue;
        for (auto &n: V[d.first].node) {
            // 出発時間
            ll t = d.second;
            if (t % n.k != 0) {
                t = (t - (t % n.k)) + n.k;
            }
            ll cost = t + n.t;
            if (C[n.n] <= cost)continue;
            C[n.n] = cost;
            q.push(pll(n.n, cost));
        }
    }

    ll ans = C[Y];
    if (ans == INF)ans = -1;
    cout << ans << endl;
    return 0;
}