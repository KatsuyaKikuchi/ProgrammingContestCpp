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
    UnionFind uf(N);
    REP(i, M) {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        uf.unit(a, b);
    }
    ll K;
    cin >> K;
    vector<pll> X;
    REP(i, K) {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        a = uf.find(a);
        b = uf.find(b);
        X.push_back(pll(std::min(a, b), std::max(a, b)));
    }

    ll Q;
    cin >> Q;
    std::map<pll, vector<ll>> mp;
    REP(i, Q) {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        a = uf.find(a);
        b = uf.find(b);
        mp[pll(std::min(a, b), std::max(a, b))].push_back(i);
    }

    vector<bool> ans(Q, true);
    std::map<pll, bool> seen;
    REP(i, K) {
        if (seen[X[i]])
            continue;
        seen[X[i]] = true;
        for (auto idx: mp[X[i]]) {
            ans[idx] = false;
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