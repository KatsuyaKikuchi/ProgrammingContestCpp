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
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

struct UnionFind {
    UnionFind(int n) {
        parent.resize(n);
        count.resize(n);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
            count[i] = 1;
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
        count[y] += count[x];
    }

    vector<int> parent;
    vector<int> count;
};

struct Data {
    ll a, b, c;
};

int main() {
    ll N;
    cin >> N;
    vector<Data> D(N - 1);
    REP(i, N - 1) {
        cin >> D[i].a >> D[i].b >> D[i].c;
        D[i].a--;
        D[i].b--;
    }
    sort(D.begin(), D.end(), [](Data a, Data b) { return a.c < b.c; });
    UnionFind uf(N);
    ll ans = 0;
    REP(i, D.size()) {
        ll a = D[i].a;
        ll b = D[i].b;
        ll c = D[i].c;
        ll ca = uf.count[uf.find(a)];
        ll cb = uf.count[uf.find(b)];
        ans += c * (ca * cb);
        uf.unit(a, b);
    }
    cout << ans << endl;
    return 0;
}