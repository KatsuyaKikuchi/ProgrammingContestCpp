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

void bfs(ll s, const vector<Vertex> &V, vector<ll> &D) {
    D[s] = 0;
    queue<ll> q;
    q.push(s);
    while (!q.empty()) {
        ll t = q.front();
        q.pop();
        ll cost = D[t] + 1;
        for (auto n: V[t].node) {
            if (D[n] <= cost)
                continue;
            D[n] = cost;
            q.push(n);
        }
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, M;
    cin >> N >> M;
    vector<Vertex> V(N);
    vector<ll> T;
    REP(i, M) {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        if (a == -1) {
            T.push_back(b);
        } else {
            V[a].node.push_back(b);
            V[b].node.push_back(a);
        }
    }

    vector<ll> DT(N, INF), DF(N, INF);
    bfs(0, V, DT);
    bfs(N - 1, V, DF);

    ll fm = INF, tm = INF;
    REP(i, T.size()) {
        fm = std::min(fm, DF[T[i]]);
        tm = std::min(tm, DT[T[i]]);
    }

    REP(i, N) {
        ll ret = std::min({DT[N - 1], DT[i] + fm + 1, tm + DF[i] + 1, INF, fm + tm + 2});
        if (ret >= INF)
            ret = -1;
        cout << ret << " ";
    }
    cout << endl;

    return 0;
}