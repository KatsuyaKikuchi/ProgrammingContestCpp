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

ll N, K;

ll dfs(const vector<Vertex> &V, ll index, ll p, ll parent = -1) {
    ll cnt = parent == -1 ? 0 : 1;
    ll ret = p;
    for (auto &n: V[index].node) {
        if (n == parent)
            continue;
        cnt++;
        ret = (ret * dfs(V, n, K - cnt, index)) % MOD;
    }
    return ret;
}

int main() {
    cin >> N >> K;
    vector<Vertex> V(N);
    REP(i, N - 1) {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        V[a].node.push_back(b);
        V[b].node.push_back(a);
    }

    ll ans = dfs(V, 0, K);
    cout << ans << endl;
    return 0;
}