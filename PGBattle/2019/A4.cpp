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
const long double PI = 3.1415926535897932384626433832795028841971;

struct Data {
    ll to;
    ll cst;
    ll d;
};

struct Vertex {
    vector<Data> node;
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, M, T, K;
    cin >> N >> M >> T >> K;
    vector<Vertex> V(N);
    REP(_, M) {
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        a--;
        b--;
        V[a].node.push_back(Data{b, c, d});
        V[b].node.push_back(Data{a, c, d});
    }

    vector<ll> C(N, INF);
    C[0] = 0;
    priority_queue<pll, vector<pll>, function<bool(pll, pll)>> q([](pll a, pll b) { return a.second > b.second; });
    q.push(pll(0, 0));
    while (!q.empty()) {
        auto t = q.top();
        q.pop();
        if (C[t.first] < t.second)
            continue;
        for (auto &d: V[t.first].node) {
            ll s = t.second;
            ll e = t.second + d.cst;
            if (e < T && d.d - abs(T - e) > K)
                e = T;
            if (s < T && e >= T && d.d > K)
                s = T;
            if (s >= T && d.d - abs(T - s) > K)
                s = d.d + T - K;
            ll cost = s + d.cst;
            if (C[d.to] <= cost)
                continue;
            C[d.to] = cost;
            q.push(pll(d.to, cost));
        }
    }

    ll ans = C[N - 1];
    if (ans == INF)
        ans = -1;

    cout << ans << endl;
    return 0;
}