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

    vector<int> parent;
    vector<int> rank;
};


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N = pow(2LL, 20);
    vector<ll> A(N, -1);

    UnionFind uf(N);
    vector<ll> V(N);
    REP(i, N) {
        V[i] = i;
    }

    ll Q;
    cin >> Q;
    REP(_, Q) {
        ll t, x;
        cin >> t >> x;
        ll value = x;
        x = (x % N);
        if (t == 1) {
            ll p = uf.find(x);
            x = V[p];
            A[x] = value;
            ll nxt;
            if (x == N - 1) {
                nxt = V[uf.find(0)];
                uf.unit(x, 0);
            } else {
                nxt = V[uf.find(x + 1)];
                uf.unit(x, x + 1);
            }
            V[uf.find(x)] = nxt;
        } else {
            cout << A[x] << endl;
        }
    }
    return 0;
}