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

struct Vertex {
    vector<ll> node;
    ll depth = 0;
    ll cost = 0;
};

void dfs(vector<Vertex> &v, ll index, ll parent = -1, ll depth = 0) {
    v[index].depth = depth;
    for (auto n: v[index].node) {
        if (n == parent)
            continue;
        dfs(v, n, index, depth + 1);
    }
}

void dfs2(vector<Vertex> &v, ll index, ll parent = -1, ll cost = 0) {
    v[index].cost += cost;
    for (auto n: v[index].node) {
        if (n == parent)
            continue;
        dfs2(v, n, index, v[index].cost);
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    vector<pll> E(N - 1);
    vector<Vertex> V(N);
    REP(i, N - 1) {
        cin >> E[i].first >> E[i].second;
        E[i].first--;
        E[i].second--;
        V[E[i].first].node.push_back(E[i].second);
        V[E[i].second].node.push_back(E[i].first);
    }

    dfs(V, 0);
    ll Q;
    cin >> Q;
    REP(_, Q) {
        ll t, e, x;
        cin >> t >> e >> x;
        e--;
        ll a = E[e].first, b = E[e].second;
        if (V[a].depth < V[b].depth) {
            if (t == 1) {
                V[0].cost += x;
                V[b].cost -= x;
            } else {
                V[b].cost += x;
            }
        } else {
            if (t == 1) {
                V[a].cost += x;
            } else {
                V[0].cost += x;
                V[a].cost -= x;
            }
        }
    }
    dfs2(V, 0);
    REP(i, N) {
        cout << V[i].cost << endl;
    }
    return 0;
}