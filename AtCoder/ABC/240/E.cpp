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
    pll range;
};

vector<Vertex> V;

void dfs(ll &count, ll index = 0, ll parent = -1) {
    ll c = 0;
    V[index].range = pll(INF, -INF);
    for (auto n: V[index].node) {
        if (n == parent)
            continue;
        c++;
        dfs(count, n, index);
        V[index].range.first = std::min(V[index].range.first, V[n].range.first);
        V[index].range.second = std::max(V[index].range.second, V[n].range.second);

    }
    if (c == 0) {
        V[index].range = pll(count, count);
        count++;
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    V.resize(N);
    REP(i, N - 1) {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        V[a].node.push_back(b);
        V[b].node.push_back(a);
    }

    ll count = 1;
    dfs(count);

    REP(i, N) {
        cout << V[i].range.first << " " << V[i].range.second << endl;
    }
    return 0;
}