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

ll dfs(const vector<Vertex> &V, ll s, ll t) {
    vector<ll> D(V.size(), INF);
    queue<pll> q;
    q.push(pll(s, 0));
    while (!q.empty()) {
        pll x = q.front();
        q.pop();
        ll cost = x.second + 1;
        for (auto n: V[x.first].node) {
            if (D[n] <= cost)
                continue;
            D[n] = cost;
            q.push(pll(n, cost));
        }
    }

    if (D[t] == INF)
        return -1;
    return D[t];
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, K;
    cin >> N >> K;
    vector<Vertex> V(N);
    REP(i, N) {
        REP(j, N) {
            ll n;
            cin >> n;
            if (n == 1)
                V[i].node.push_back(j);
        }
    }

    ll Q;
    cin >> Q;
    REP(_, Q) {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        a %= N;
        b %= N;

        cout << dfs(V, a, b) << endl;
    }
    return 0;
}