#include <bits/stdc++.h>

using namespace std;
using ll = long long int;
using pll = pair<ll, ll>;

#define FOR(i, n, m) for(ll i = (m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;
const ll MAX = (ll) 1e9;
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
        ll a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        V[a].node.push_back(pll(b, c));
        V[b].node.push_back(pll(a, -c));
    }

    vector<bool> seen(N, false);
    vector<ll> D(N, 0);
    REP(i, N) {
        if (seen[i])
            continue;
        seen[i] = true;
        queue<ll> q;
        q.push(i);
        pll dist(0, 0);
        while (!q.empty()) {
            ll t = q.front();
            q.pop();
            for (auto n: V[t].node) {
                ll d = n.second + D[t];
                ll nxt = n.first;
                if (seen[nxt]) {
                    if (d != D[nxt]) {
                        cout << "No" << endl;
                        return 0;
                    }
                } else {
                    seen[nxt] = true;
                    D[nxt] = d;
                    dist.first = std::min(dist.first, D[nxt]);
                    dist.second = std::max(dist.second, D[nxt]);
                    q.push(nxt);
                }
            }
        }

        if (dist.second - dist.first > MAX) {
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;

    return 0;
}