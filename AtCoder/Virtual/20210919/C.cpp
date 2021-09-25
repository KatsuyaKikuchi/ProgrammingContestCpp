#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <queue>
#include <stack>

using namespace std;
using ll = long long int;
using pll = pair<ll, ll>;

#define FOR(i, n, m) for(ll i = (m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

struct Data {
    ll a, b, c;
};

struct UnionFind {
    UnionFind(int n) {
        parent.resize(n);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    int find(int x) {
        int p = parent[x];
        if (p == x)
            return x;
        return parent[x] = find(p);
    }

    bool same(int x, int y) {
        return find(x) == find(y);
    }

    void unit(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y)
            return;

        parent[x] = y;
    }

    vector<int> parent;
};

int main() {
    ll N, M;
    cin >> N >> M;
    vector<Data> D;
    REP(i, M) {
        ll a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        D.push_back(Data{a, b, c});
    }
    sort(D.begin(), D.end(), [](Data a, Data b) { return a.c < b.c; });
    ll ans = 0;
    UnionFind uf(N);
    REP(i, M) {
        auto d = D[i];
        if (uf.same(d.a, d.b)) {
            ans += std::max(0LL, d.c);
            continue;
        }
        uf.unit(d.a, d.b);
    }
    cout << ans << endl;
    return 0;
}