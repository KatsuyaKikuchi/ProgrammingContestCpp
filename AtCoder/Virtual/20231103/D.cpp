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
    vector<ll> node;
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, M, K;
    cin >> N >> M >> K;
    vector<Vertex> V(N);
    REP(_, M) {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        V[a].node.push_back(b);
        V[b].node.push_back(a);
    }

    vector<ll> D(N, -INF);
    REP(i, K) {
        ll p, h;
        cin >> p >> h;
        p--;
        D[p] = std::max(D[p], h);
    }

    priority_queue<pll, vector<pll>, function<bool(pll, pll)>> q([](pll a, pll b) { return a.second < b.second; });
    REP(i, N) {
        if (D[i] >= 0)
            q.push(pll(i, D[i]));
    }

    while (!q.empty()) {
        pll t = q.top();
        q.pop();
        if (D[t.first] > t.second)
            continue;
        ll cost = t.second - 1;
        for (auto n: V[t.first].node) {
            if (D[n] >= cost)
                continue;
            D[n] = cost;
            q.push(pll(n, cost));
        }
    }

    vector<ll> ans;
    REP(i, N) {
        if (D[i] >= 0)
            ans.push_back(i + 1);
    }
    cout << ans.size() << endl;
    for (auto n: ans) {
        cout << n << " ";
    }
    cout << endl;
    return 0;
}