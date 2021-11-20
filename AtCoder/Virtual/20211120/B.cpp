#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <queue>
#include <stack>
#include <iomanip>
#include <cmath>
#include <map>
#include <set>

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
    ll parent = -1;
    ll sum = 0;
    ll count = 0;
};

ll dfs(vector<Vertex> &v, ll index, ll parent = -1) {
    v[index].parent = parent;
    v[index].count = 1;
    v[index].sum = 0;
    for (auto n: v[index].node) {
        if (n == parent)
            continue;
        v[index].count += dfs(v, n, index);
        v[index].sum += v[n].sum + v[n].count;
    }
    return v[index].count;
}

ll N;

void dfs2(vector<Vertex> &v, ll index) {
    ll p = v[index].parent;
    if (p >= 0) {
        ll s = v[p].sum - (v[index].sum + v[index].count);
        v[index].sum += s + (N - v[index].count);
    }

    for (auto n: v[index].node) {
        if (n == p)
            continue;
        dfs2(v, n);
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    vector<Vertex> V(N);
    REP(_, N - 1) {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        V[a].node.push_back(b);
        V[b].node.push_back(a);
    }
    dfs(V, 0);
    dfs2(V, 0);

    REP(i, N) {
        cout << V[i].sum << endl;
    }
    return 0;
}