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
    vector<pll> node;
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, M;
    cin >> N >> M;
    vector<Vertex> V(N);
    REP(i, M) {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        V[a].node.push_back(pll(b, i));
        V[b].node.push_back(pll(a, i));
    }

    ll ans = 0;
    vector<bool> U(N, false);
    vector<bool> E(M, false);
    REP(i, N) {
        if (U[i])
            continue;
        U[i] = true;
        queue<ll> q;
        q.push(i);
        while (!q.empty()) {
            ll t = q.front();
            q.pop();
            for (auto n: V[t].node) {
                if (E[n.second])
                    continue;
                E[n.second] = true;
                if (U[n.first]) {
                    ans++;
                    continue;
                }
                U[n.first] = true;
                q.push(n.first);
            }
        }

    }
    cout << ans << endl;
    return 0;
}