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
    ll depth;
};

void dfs(vector<Vertex> &v, ll index, ll parent = -1) {
    v[index].depth = parent == -1 ? 0 : v[parent].depth + 1;
    for (auto &nxt: v[index].node) {
        if (nxt == parent)
            continue;
        dfs(v, nxt, index);
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
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

    vector<ll> odd, even;
    REP(i, N) {
        if (V[i].depth % 2 == 0)even.push_back(i + 1);
        else odd.push_back(i + 1);
    }

    if (odd.size() > even.size())
        swap(odd, even);

    REP(i, N / 2) {
        cout << even[i] << " ";
    }
    cout << endl;
    return 0;
}