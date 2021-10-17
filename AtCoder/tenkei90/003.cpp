#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <queue>
#include <stack>

using namespace std;
using ll = long long int;
using pll = pair<ll, ll>;

#define FOR(i, n, m) for(ll i = (m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

struct Vertex {
    vector<ll> node;
};

pll dfs(vector<Vertex> &v, ll index, ll parent = -1) {
    pll ret(index, 0);
    for (auto &n: v[index].node) {
        if (n == parent)
            continue;
        pll t = dfs(v, n, index);
        if (t.second + 1 > ret.second)
            ret = pll(t.first, t.second + 1);
    }
    return ret;
}

int main() {
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

    pll a = dfs(V, 0);
    pll b = dfs(V, a.first);
    cout << b.second + 1 << endl;

    return 0;
}