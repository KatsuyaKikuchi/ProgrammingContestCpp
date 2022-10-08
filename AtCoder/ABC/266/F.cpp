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
    ll depth;
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

pll p(-1, -1);
bool seen[200005];

void dfs(vector<Vertex> &V, ll index = 0, ll parent = -1, ll depth = 0, bool update = true) {
    seen[index] = true;
    V[index].parent = parent;
    V[index].depth = depth;
    for (auto n: V[index].node) {
        if (n == parent)
            continue;
        if (seen[n]) {
            if (update)
                p = pll(index, n);
            continue;
        }
        dfs(V, n, index, depth + 1);
    }
}

void dfs2(vector<Vertex> &V, ll index, UnionFind &uf, const vector<bool> &use) {
    for (auto n: V[index].node) {
        if (V[index].parent == n)
            continue;
        if (use[n])
            continue;
        //if (index != p.first && index != p.second)
        uf.unit(index, n);
        dfs2(V, n, uf, use);
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    vector<Vertex> V(N);
    REP(i, N) {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        V[a].node.push_back(b);
        V[b].node.push_back(a);
    }
    memset(seen, 0, sizeof(seen));
    dfs(V);
    memset(seen, 0, sizeof(seen));
    dfs(V, p.first, -1, 0);

    vector<bool> U(N, false);
    vector<ll> v;
    ll index = p.first;
    if (V[p.first].depth < V[p.second].depth)
        index = p.second;
    while (index >= 0) {
        v.push_back(index);
        index = V[index].parent;
        if (index == p.first || index == p.second) {
            REP(i, v.size()) {
                U[v[i]] = true;
            }
            U[p.first] = true;
            U[p.second] = true;
            break;
        }
    }

    vector<ll> t;
    REP(i, N) {
        if (U[i])
            continue;
        if (V[i].parent >= 0 && U[V[i].parent])
            t.push_back(V[i].parent);
    }
    sort(t.begin(), t.end());
    t.erase(unique(t.begin(), t.end()), t.end());

    UnionFind uf(N);
    REP(i, t.size()) {
        dfs2(V, t[i], uf, U);
    }

    ll Q;
    cin >> Q;
    REP(i, Q) {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        if (uf.same(a, b))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }

    return 0;
}