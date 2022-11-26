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

ll N;

ll calc(ll x) {
    ll count = 0;
    REP(i, 24) {
        if ((x >> i) & 1)
            count++;
    }
    if (count < N + 1)
        return 0;
    ll ret = INF;
    REP(i, 24) {
        if (((x >> i) & 1) == 0)
            continue;
        FOR(j, 24, i + 1) {
            if (((x >> j) & 1) == 0)
                continue;
            ll d = std::max(i, j) - std::min(i, j);
            ret = std::min(ret, std::min(d, 24 - d));
        }
    }
    return ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    vector<ll> D(N);
    REP(i, N) {
        cin >> D[i];
    }

    if (N >= 24) {
        cout << 0 << endl;
        return 0;
    }

    ll ans = 0;
    ll MAX = pow(2LL, N);
    REP(bit, MAX) {
        ll t = 1;
        REP(i, N) {
            if (((bit >> i) & 1) || (D[i] == 0))
                t |= (1LL << D[i]);
            else
                t |= (1LL << (24 - D[i]));
        }
        ll s = calc(t);
        ans = std::max(ans, s);
    }

    cout << ans << endl;

    return 0;
}