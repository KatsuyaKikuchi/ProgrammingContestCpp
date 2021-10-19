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

    vector<int> parent;
    vector<int> rank;
};

ll x[4] = {0, 1, 0, -1};
ll y[4] = {1, 0, -1, 0};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll H, W;
    cin >> H >> W;
    ll Q;
    cin >> Q;
    UnionFind uf(H * W);
    vector<bool> G(H * W, false);
    REP(_, Q) {
        ll t;
        cin >> t;
        if (t == 1) {
            ll a, b;
            cin >> a >> b;
            a--;
            b--;
            ll n = a * W + b;
            G[n] = true;
            REP(i, 4) {
                ll nx = x[i] + a, ny = y[i] + b;
                if (nx < 0 || nx >= H || ny < 0 || ny >= W)
                    continue;
                ll m = nx * W + ny;
                if (G[m])
                    uf.unit(n, m);
            }

        } else {
            ll a, b, c, d;
            cin >> a >> b >> c >> d;
            a--;
            b--;
            c--;
            d--;
            ll n = a * W + b, m = c * W + d;
            if (uf.same(n, m) && G[n] && G[m])
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        }
    }
    return 0;
}