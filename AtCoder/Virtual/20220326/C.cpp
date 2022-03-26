#include <bits/stdc++.h>
#include "../../atcoder/all"

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

ll op(ll l, ll r) { return std::min(l, r); }

ll e() { return INF; }

ll mapping(ll l, ll r) { return l + r; }

ll composition(ll l, ll r) { return l + r; }

ll id() { return 0; }

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, Q;
    cin >> N >> Q;
    string S;
    cin >> S;

    vector<ll> v(N);
    ll d = 0;
    REP(i, N) {
        if (S[i] == '(')d++;
        else d--;
        v[i] = d;
    }

    lazy_segtree<ll, op, e, ll, mapping, composition, id> seg(v);

    REP(_, Q) {
        ll t, l, r;
        cin >> t >> l >> r;
        l--;
        if (t == 1) {
            swap(S[l], S[r - 1]);
            if (S[l] == S[r - 1])
                continue;
            if (S[l] == '(')
                seg.apply(l, r - 1, 2);
            else
                seg.apply(l, r - 1, -2);

        } else {
            ll mn = seg.prod(l, r);
            ll rn = seg.get(r - 1);
            ll ln = 0;
            if (l > 0)
                ln = seg.get(l - 1);
            if (rn == ln && mn - ln >= 0)
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        }
    }
    return 0;
}