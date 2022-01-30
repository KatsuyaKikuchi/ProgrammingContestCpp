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
    vector<ll> A(N);
    REP(i, N) {
        cin >> A[i];
    }
    UnionFind uf(N);
    REP(_, M) {
        ll a, b;
        cin >> a >> b;
        uf.unit(a, b);
    }

    auto g = uf.groups();
    ll vs = (g.size() - 1) * 2;
    if (vs > N) {
        cout << "Impossible" << endl;
        return 0;
    }
    if (vs == 0) {
        cout << 0 << endl;
        return 0;
    }
    priority_queue<ll, vector<ll>, greater<ll>> q;
    ll ans = 0;
    for (auto t: g) {
        vector<ll> v;
        for (auto i: t) {
            v.push_back(A[i]);
        }
        sort(v.begin(), v.end());
        ans += v[0];
        vs--;
        FOR(i, v.size(), 1) {
            q.push(v[i]);
        }
    }

    while (vs > 0) {
        ans += q.top();
        q.pop();
        vs--;
    }
    cout << ans << endl;
    return 0;
}