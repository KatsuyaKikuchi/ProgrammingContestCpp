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

struct Data {
    pll c;
    ll r;
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
    ll N;
    cin >> N;
    pll s, t;
    cin >> s.first >> s.second >> t.first >> t.second;
    vector<Data> D(N);
    REP(i, N) {
        cin >> D[i].c.first >> D[i].c.second >> D[i].r;\

    }

    UnionFind uf(N + 2);
    REP(i, N) {
        REP(j, i) {
            ll x = D[i].c.first - D[j].c.first;
            ll y = D[i].c.second - D[j].c.second;
            ll len = x * x + y * y;
            if (len <= (D[i].r + D[j].r) * (D[i].r + D[j].r) &&
                    len >= (D[i].r - D[j].r) * (D[i].r - D[j].r)) {
                uf.unit(i + 2, j + 2);
            }
        }
    }
    REP(i, N) {
        {
            ll x = D[i].c.first - s.first;
            ll y = D[i].c.second - s.second;
            ll len = x * x + y * y;
            if (len == (D[i].r) * (D[i].r)) {
                uf.unit(i + 2, 0);
            }
        }
        {
            ll x = D[i].c.first - t.first;
            ll y = D[i].c.second - t.second;
            ll len = x * x + y * y;
            if (len == (D[i].r) * (D[i].r)) {
                uf.unit(i + 2, 1);
            }
        }
    }

    if (uf.same(0, 1))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}