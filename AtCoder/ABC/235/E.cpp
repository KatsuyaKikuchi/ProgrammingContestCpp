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

struct Edge {
    ll a, b, c;
    ll query;
};

struct UnionFind {
    UnionFind(int size) {
        parent.resize(size);
        rank.resize(size);
        for (int i = 0; i < size; ++i) {
            parent[i] = i;
            rank[i] = 1;
        }
    }

    int find(int x) {
        if (parent[x] == x)
            return x;
        return parent[x] = find(parent[x]);
    }

    bool same(int x, int y) {
        return find(x) == find(y);
    }

    int unit(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y)
            return x;
        if (rank[x] < rank[y])
            swap(x, y);
        parent[y] = x;
        rank[x] += rank[y];
        return x;
    }

    vector<vector<int>> groups() {
        vector<ll> g;
        for (int i = 0; i < parent.size(); ++i) {
            ll p = find(i);
            g.push_back(p);
        }
        sort(g.begin(), g.end());
        g.erase(unique(g.begin(), g.end()), g.end());

        vector<vector<int>> ret(g.size());
        for (int i = 0; i < parent.size(); ++i) {
            auto index = lower_bound(g.begin(), g.end(), find(i)) - g.begin();
            ret[index].push_back(i);
        }
        return ret;
    }

    vector<int> parent;
    vector<int> rank;
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll N, M, Q;
    cin >> N >> M >> Q;
    vector<Edge> E;
    REP(i, M) {
        ll a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        E.push_back(Edge{a, b, c, -1});
    }
    REP(i, Q) {
        ll a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        E.push_back(Edge{a, b, c, i});
    }
    sort(E.begin(), E.end(), [](Edge a, Edge b) { return a.c < b.c; });
    vector<bool> ans(Q, false);

    UnionFind uf(N);

    REP(i, E.size()) {
        auto e = E[i];
        if (e.query < 0) {
            uf.unit(e.a, e.b);
        } else {
            ll q = e.query;

            ans[q] = !uf.same(e.a, e.b);
        }
    }

    REP(i, Q) {
        if (ans[i])
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }

    return 0;
}