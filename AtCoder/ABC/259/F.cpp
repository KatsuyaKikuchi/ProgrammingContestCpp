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
    ll count;
    vector<pll> node;
};

vector<Vertex> V;

pll dfs(ll index, ll parent = -1) {
    ll sum = 0;
    vector<ll> v;
    for (auto n: V[index].node) {
        if (n.first == parent)
            continue;
        auto p = dfs(n.first, index);
        v.push_back(n.second + p.second - p.first);
        sum += p.first;
    }
    ll count = V[index].count;
    sort(v.begin(), v.end(), greater<ll>());
    REP(i, std::min((ll) v.size(), V[index].count - 1)) {
        sum = std::max(sum, sum + v[i]);
    }
    pll ret = pll(sum, sum);
    if (count == 0) {
        ret.second = -INF;
    } else if (count <= v.size()) {
        ret.first += std::max(0LL, v[count - 1]);
    }

    return ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    V.resize(N);
    REP(i, N) {
        cin >> V[i].count;
    }

    REP(i, N - 1) {
        ll a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        V[a].node.emplace_back(b, c);
        V[b].node.emplace_back(a, c);
    }

    pll ans = dfs(0);
    cout << std::max(ans.first, ans.second) << endl;
    return 0;
}