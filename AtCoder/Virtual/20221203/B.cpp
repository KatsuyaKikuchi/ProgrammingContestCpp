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
    pll ans;
};

pll dfs(vector<Vertex> &V, ll &count, ll index = 0, ll parent = -1) {
    pll ret(INF, -1);
    for (auto n: V[index].node) {
        if (n == parent)
            continue;
        pll t = dfs(V, count, n, index);
        ret.first = std::min(ret.first, t.first);
        ret.second = std::max(ret.second, t.second);
    }
    if (ret.first == INF) {
        ret = pll(count, count);
        count++;
    }
    V[index].ans = ret;
    return ret;
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

    ll count = 1;
    dfs(V, count);
    REP(i, N) {
        cout << V[i].ans.first << " " << V[i].ans.second << endl;
    }

    return 0;
}