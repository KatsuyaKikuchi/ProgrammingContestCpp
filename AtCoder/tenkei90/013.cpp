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

struct Vertex {
    vector<pll> node;
};

vector<ll> solve(ll s, const vector<Vertex> &V) {
    ll N = V.size();
    vector<ll> ret(N, INF);
    ret[s] = 0;
    priority_queue<pll, vector<pll>, function<bool(pll, pll)>> q([](pll a, pll b) { return a.second > b.second; });
    q.push(pll(s, 0));
    while (!q.empty()) {
        auto t = q.top();
        q.pop();
        if (ret[t.first] < t.second)
            continue;
        for (auto &n: V[t.first].node) {
            ll nxt = n.first;
            ll cost = n.second + t.second;
            if (ret[nxt] <= cost)
                continue;
            ret[nxt] = cost;
            q.push(pll(nxt, cost));
        }
    }
    return ret;
}

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
        V[b].node.push_back(pll(a, c));
    }
    vector<ll> F = solve(0, V);
    vector<ll> T = solve(N - 1, V);
    REP(i, N) {
        cout << T[i] + F[i] << endl;
    }
    return 0;
}