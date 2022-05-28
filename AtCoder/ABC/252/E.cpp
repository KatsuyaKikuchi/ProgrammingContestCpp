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
    ll to;
    ll cost;
    ll index;
};
struct Vertex {
    vector<Edge> node;
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, M;
    cin >> N >> M;
    vector<Vertex> V(N);
    REP(i, M) {
        ll a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        V[a].node.push_back(Edge{b, c, i});
        V[b].node.push_back(Edge{a, c, i});
    }

    vector<ll> ans;

    priority_queue<Edge, vector<Edge>, function<bool(Edge, Edge)>> q([](Edge a, Edge b) { return a.cost > b.cost; });
    q.push(Edge{0, 0, -1});
    vector<ll> D(N, INF);
    D[0] = 0;
    while (!q.empty()) {
        Edge e = q.top();
        q.pop();
        if (D[e.to] < e.cost)
            continue;
        if (e.index >= 0)
            ans.push_back(e.index);

        for (auto nxt: V[e.to].node) {
            ll n = nxt.to;
            ll cost = nxt.cost + e.cost;
            if (D[n] <= cost)
                continue;
            D[n] = cost;
            q.push(Edge{n, cost, nxt.index});
        }
    }

    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());
    REP(i, ans.size()) {
        cout << ans[i] + 1 << " ";
    }
    cout << endl;

    return 0;
}