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

    vector<bool> used(M, false);
    REP(i, N) {
        vector<ll> C(N, INF);
        C[i] = 0;
        {
            priority_queue<pll, vector<pll>, function<bool(pll, pll)>> q(
                    [](pll a, pll b) { return a.second > b.second; });
            q.push(pll(i, 0));
            while (!q.empty()) {
                auto t = q.top();
                q.pop();
                if (C[t.first] < t.second)
                    continue;
                for (auto n: V[t.first].node) {
                    ll cost = t.second + n.cost;
                    if (C[n.to] <= cost)
                        continue;
                    C[n.to] = cost;
                    q.push(pll(n.to, cost));
                }
            }
        }
        FOR(j, N, i + 1) {
            queue<ll> q;
            q.push(j);
            vector<bool> seen(N, false);
            while (!q.empty()) {
                auto t = q.front();
                q.pop();
                for (auto &n: V[t].node) {
                    if (C[n.to] + n.cost != C[t])
                        continue;
                    used[n.index] = true;
                    if (seen[n.to])
                        continue;
                    seen[n.to] = true;
                    q.push(n.to);
                }
            }
        }
    }
    ll ans = 0;
    REP(i, M) {
        if (!used[i])
            ans++;
    }
    cout << ans << endl;
    return 0;
}