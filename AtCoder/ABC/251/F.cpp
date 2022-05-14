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

vector<pll> t0, t1;

void dfs0(const vector<Vertex> &V, vector<bool> &seen, ll index = 0, ll parent = -1) {
    seen[index] = true;
    for (auto n: V[index].node) {
        if (seen[n])
            continue;
        t0.emplace_back(index, n);
        dfs0(V, seen, n, index);
    }
}

void dfs1(const vector<Vertex> &V, vector<bool> &seen, ll index = 0, ll parent = -1) {
    seen[index] = true;
    vector<ll> nxt;
    for (auto n: V[index].node) {
        if (seen[n])
            continue;
        seen[n] = true;
        nxt.push_back(n);
        t1.emplace_back(index, n);
    }
    for (auto n: nxt) {
        dfs1(V, seen, n, index);
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, M;
    cin >> N >> M;
    vector<Vertex> V(N);
    REP(_, M) {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        V[a].node.push_back(b);
        V[b].node.push_back(a);
    }

    vector<bool> seen0(N, false);
    vector<bool> seen1(N, false);
    dfs0(V, seen0);
    dfs1(V, seen1);

    REP(i, t0.size()) {
        cout << t0[i].first + 1 << " " << t0[i].second + 1 << endl;
    }
  //  cout << " " << endl;
    REP(i, t1.size()) {
        cout << t1[i].first + 1 << " " << t1[i].second + 1 << endl;
    }
    return 0;
}