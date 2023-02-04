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
    ll parent;
    bool white = false;
};

void dfs(vector<Vertex> &V, ll index = 0, ll parent = -1) {
    V[index].parent = parent;
    for (auto n: V[index].node) {
        if (n == parent)
            continue;
        dfs(V, n, index);
    }
}

ll dfs2(vector<Vertex> &V, ll index = 0, ll parent = -1) {
    if (V[index].white) {
        return 0;
    }
    ll ret = 1;
    for (auto n: V[index].node) {
        if (n == parent)
            continue;
        ret += dfs2(V, n, index);
    }
    return ret;
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
        V[a].node.push_back(b);
        V[b].node.push_back(a);
    }
    dfs(V);
    ll count = 0;
    {
        ll p = V[N - 1].parent;
        while (p != 0) {
            p = V[p].parent;
            count++;
        }
    }
    count /= 2;
    {
        ll index = N - 1;
        while (count >= 0) {
            V[index].white = true;
            count--;
            index = V[index].parent;
        }
    }

    ll sum = dfs2(V);
    if (N / 2 + 1 <= sum) {
        cout << "Fennec" << endl;
    } else {
        cout << "Snuke" << endl;
    }
    return 0;
}