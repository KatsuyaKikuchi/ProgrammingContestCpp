#include <bits/stdc++.h>
#include "atcoder/all"

using namespace atcoder;

using namespace std;
using ll = long long int;
using pll = pair<ll, ll>;

#define FOR(i, n, m) for(ll i = (m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;
const long double PI = 3.1415926535897932384626433832795028841971;

struct Query {
    ll t;
    ll l, r, x;
    ll i, j;
};

struct S {
    ll value;
    ll size;
};
using F = ll;

S op(S a, S b) { return {a.value + b.value, a.size + b.size}; }

S e() { return {0, 0}; }

S mapping(F f, S x) { return {x.value + x.size * f, x.size}; }

F composition(F f, F g) { return f + g; }

F id() { return 0; }

struct Data {
    ll index;
    ll width;
    ll value;
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll H, W, Q;
    cin >> H >> W >> Q;
    vector<Query> query(Q);
    REP(i, Q) {
        ll t;
        cin >> t;
        query[i].t = t;
        if (t == 1) {
            cin >> query[i].l >> query[i].r >> query[i].x;
        } else if (t == 2) {
            cin >> query[i].i >> query[i].x;
        } else {
            cin >> query[i].i >> query[i].j;
        }
        query[i].i--;
        query[i].j--;
        query[i].l--;
        query[i].r--;
    }

    std::vector<S> v(W + 5, {0, 1});
    atcoder::lazy_segtree<S, op, e, F, mapping, composition, id> seg(v);

    vector<stack<Data>> vec(H + 5);
    vector<pll> ans(Q, pll(-1, 0));
    for (ll nn = Q - 1; nn >= 0; --nn) {

#if false
        REP(i, W) {
            cout << seg.get(i).value << " ";
        }
        cout << endl;
#endif

        auto q = query[nn];
        if (q.t == 1) {
            seg.apply(q.l, q.r + 1, q.x);
            continue;
        }
        if (q.t == 3) {
            Data d{nn, q.j, 0};
            d.value -= seg.get(q.j).value;
            vec[q.i].push(d);
            continue;
        }

        while (!vec[q.i].empty()) {
            auto d = vec[q.i].top();
            vec[q.i].pop();

            ans[d.index] = pll(0, q.x + d.value + seg.get(d.width).value);
        }
    }

    REP(i, H) {
        while (!vec[i].empty()) {
            auto d = vec[i].top();
            vec[i].pop();

            ans[d.index] = pll(0, d.value + seg.get(d.width).value);
        }
    }

    REP(i, Q) {
        if (ans[i].first < 0)
            continue;
        cout << ans[i].second << endl;
    }

    return 0;
}