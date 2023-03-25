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
    ll count = 0;
    ll dis = 0;
    ll ans = 0;
};

ll dfs0(vector<Vertex> &V, ll index, ll parent = -1) {
    V[index].count = 1;
    for (auto n: V[index].node) {
        if (parent == n)
            continue;
        V[index].count += dfs0(V, n, index);
    }

    return V[index].count;
}

ll dfs1(vector<Vertex> &V, ll index, ll parent = -1) {
    V[index].dis = 0;
    for (auto n: V[index].node) {
        if (parent == n)
            continue;
        V[index].dis += dfs1(V, n, index);
    }

    return V[index].dis + V[index].count;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    vector<Vertex> V(N);
    REP(i, N - 1) {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        V[a].node.push_back(b);
        V[b].node.push_back(a);
    }
    dfs0(V, 0);
    dfs1(V, 0);
    V[0].ans = V[0].dis;
    queue<pll> q;
    q.push(pll(0, -1));
    while (!q.empty()) {
        pll t = q.front();
        q.pop();
        for (auto n: V[t.first].node) {
            if (n == t.second)
                continue;
            V[n].ans = V[t.first].ans + N - V[n].count - (V[n].count);
            q.push(pll(n, t.first));
        }
    }

    REP(i, N) {
        cout << V[i].ans << endl;
    }
    return 0;
}