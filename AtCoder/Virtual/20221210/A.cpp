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
    ll color;
};

ll C[100005];
vector<ll> ans;

void dfs(const vector<Vertex> &V, ll index = 0, ll parent = -1) {
    if (C[V[index].color] == 0)
        ans.push_back(index);
    C[V[index].color]++;
    for (auto n: V[index].node) {
        if (n == parent)
            continue;
        dfs(V, n, index);
    }
    C[V[index].color]--;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    vector<Vertex> V(N);
    REP(i, N) {
        cin >> V[i].color;
    }
    REP(i, N - 1) {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        V[a].node.push_back(b);
        V[b].node.push_back(a);
    }

    dfs(V);
    sort(ans.begin(), ans.end());
    REP(i, ans.size()) {
        cout << ans[i] + 1 << endl;
    }
    return 0;
}