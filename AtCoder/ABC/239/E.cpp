#include <bits/stdc++.h>

using namespace std;
using ll = long long int;
using pll = pair<ll, ll>;

#define FOR(i, n, m) for(ll i = (m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll MAX = 25;
const ll INF = (ll) 1e15;
const long double PI = 3.1415926535897932384626433832795028841971;

struct Vertex {
    vector<ll> node;
    ll x;
    ll q[MAX];
};

void dfs(vector<Vertex> &V, ll index = 0, ll parent = -1) {
    priority_queue<ll, vector<ll>, function<bool(ll, ll)>> q([](ll a, ll b) { return a > b; });
    REP(i, MAX) {
        V[index].q[i] = -INF;
    }
    q.push(V[index].x);

    for (auto nxt: V[index].node) {
        if (nxt == parent)
            continue;
        dfs(V, nxt, index);
        REP(i, MAX) {
            q.push(V[nxt].q[i]);
        }

        while (q.size() > MAX)
            q.pop();
    }

    vector<ll> v;
    while (!q.empty()) {
        v.push_back(q.top());
        q.pop();
    }
    sort(v.begin(), v.end(), greater<ll>());
    REP(i, v.size()) {
        V[index].q[i] = v[i];
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, Q;
    cin >> N >> Q;
    vector<Vertex> V(N);
    REP(i, N) {
        cin >> V[i].x;
    }

    REP(_, N - 1) {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        V[a].node.push_back(b);
        V[b].node.push_back(a);
    }

    dfs(V);

    REP(_, Q) {
        ll v, k;
        cin >> v >> k;
        v--;
        cout << V[v].q[k - 1] << endl;
    }

    return 0;
}