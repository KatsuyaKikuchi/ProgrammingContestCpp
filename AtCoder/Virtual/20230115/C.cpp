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

ll ans[100005];

void dfs(vector<Vertex> &V, ll index = 0, ll parent = -1, ll color = 0) {
    ll c = 1;
    while (true) {
        if (c != color)
            break;
        c++;
    }
    for (auto n: V[index].node) {
        if (n.first == parent)
            continue;
        ans[n.second] = c;
        dfs(V, n.first, index, c);
        while (true) {
            c++;
            if (c != color)
                break;
        }
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    vector<Vertex> V(N);
    REP(i, N - 1) {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        V[a].node.push_back(pll(b, i));
        V[b].node.push_back(pll(a, i));
    }

    dfs(V);
    ll t = 0;
    REP(i, N - 1) {
        t = std::max(t, ans[i]);
    }
    cout << t << endl;
    REP(i, N - 1) {
        cout << ans[i] << endl;
    }
    return 0;
}