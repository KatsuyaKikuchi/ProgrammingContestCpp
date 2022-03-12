#include <bits/stdc++.h>

using namespace std;
using ll = long long int;
using pll = pair<ll, ll>;

#define FOR(i, n, m) for(ll i = (m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e18;
const long double PI = 3.1415926535897932384626433832795028841971;

struct Vertex {
    vector<pll> node;
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, M;
    cin >> N >> M;
    vector<ll> A(N);
    REP(i, N) {
        cin >> A[i];
    }
    vector<Vertex> V(N);
    REP(_, M) {
        ll a, b;
        cin >> a >> b;
        a--;
        --b;
        {
            ll c = 0;
            if (A[a] < A[b])
                c = A[b] - A[a];
            V[a].node.push_back(pll(b, c));
        }
        {
            ll c = 0;
            if (A[b] < A[a])
                c = A[a] - A[b];
            V[b].node.push_back(pll(a, c));
        }
    }
    vector<ll> D(N, INF);
    D[0] = 0;

    priority_queue<pll, vector<pll>, function<bool(pll, pll)>> q([](pll a, pll b) { return a.second > b.second; });
    q.push(pll(0, 0));
    while (!q.empty()) {
        pll t = q.top();
        q.pop();
        if (D[t.first] < t.second)
            continue;
        for (auto n: V[t.first].node) {
            ll nxt = n.first;
            ll cost = n.second + t.second;
            if (D[nxt] <= cost)
                continue;
            D[nxt] = cost;
            q.push(pll(nxt, cost));
        }
    }

    ll ans = 0;
    REP(i, N) {
        //cout << D[i] << endl;
        ans = std::max(ans, A[0] - A[i] - D[i]);
    }
    cout << ans << endl;

    return 0;
}