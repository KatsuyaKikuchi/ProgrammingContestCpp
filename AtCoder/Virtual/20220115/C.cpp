#include <bits/stdc++.h>

using namespace std;
using ll = long long int;
using pll = pair<ll, ll>;

#define FOR(i, n, m) for(ll i = (m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 998244353;
const ll INF = (ll) 1e15;
const long double PI = 3.1415926535897932384626433832795028841971;

struct Vertex {
    vector<ll> node;
    ll count = 0;
    bool enable;
};

ll modpow(ll n, ll r, ll mod) {
    ll ret = 1;
    ll p = n;
    while (r > 0) {
        if ((r & 1) == 1)
            ret = (ret * p) % mod;
        p = (p * p) % mod;
        r /= 2;
    }
    return ret;
}

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
    ll N, M;
    cin >> N >> M;
    vector<Vertex> V(N);
    REP(i, M) {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        V[a].node.push_back(b);
        V[b].node.push_back(a);
    }

    queue<ll> q;
    REP(i, N) {
        V[i].count = V[i].node.size();
        V[i].enable = false;
        if (V[i].count == 1)
            q.push(i);
    }

    while (!q.empty()) {
        ll t = q.front();
        q.pop();
        if (V[t].count != 1 || V[t].enable)
            continue;
        V[t].enable = true;
        for (auto n: V[t].node) {
            if (V[n].enable)
                continue;
            V[n].count--;
            if (V[n].count == 1)
                q.push(n);
        }
    }

    vector<ll> v;
    REP(i, N) {
        if (V[i].enable)
            continue;

        if (V[i].count != 2) {
            cout << 0 << endl;
            return 0;
        } else
            v.push_back(i);
    }

    UnionFind uf(v.size());
    REP(i, v.size()) {
        ll t = v[i];
        V[t].enable = true;
        for (auto n: V[t].node) {
            if (V[n].enable)
                continue;
            auto index = lower_bound(v.begin(), v.end(), n) - v.begin();
            uf.unit(i, index);
        }
    }

    auto group = uf.groups();

    cout << modpow(2, group.size(), MOD) << endl;

    return 0;
}