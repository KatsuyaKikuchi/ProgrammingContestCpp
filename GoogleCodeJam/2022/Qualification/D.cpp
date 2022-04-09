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
    ll value;
    vector<ll> child;
};

pll dfs(const vector<Vertex> &V, ll index) {
    pll ret(0, 0);
    ll min = INF;
    ll minSum = 0;
    for (auto c: V[index].child) {
        pll r = dfs(V, c);
        ret.first += r.first;
        min = std::min(min, r.second);
        minSum += r.second;
    }

    if (min == INF) {
        ret.second = V[index].value;
    } else {
        ret.first += minSum - min;
        ret.second = std::max(V[index].value, min);
    }

    return ret;
}

ll solve() {
    ll N;
    cin >> N;
    vector<Vertex> V(N);
    REP(i, N) {
        cin >> V[i].value;
    }

    vector<ll> P;
    REP(i, N) {
        ll p;
        cin >> p;
        if (p > 0)
            V[p - 1].child.push_back(i);
        else
            P.push_back(i);
    }

    ll ans = 0;
    REP(i, P.size()) {
        auto ret = dfs(V, P[i]);
        ans += ret.first + ret.second;
    }
    return ans;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll T;
    cin >> T;
    REP(i, T) {
        cout << "Case #" << i + 1 << ": " << solve() << endl;
    }
    return 0;
}