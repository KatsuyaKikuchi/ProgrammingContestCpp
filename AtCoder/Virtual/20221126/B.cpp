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

ll query(ll a, ll b, ll c, ll d) {
    cout << "? " << a << " " << b << " " << c << " " << d << endl;
    ll ret;
    cin >> ret;
    return ret;
}

ll result(ll x, ll y) {
    cout << "! " << x << " " << y << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    ll h, w;
    {
        ll ng = 0, ok = N;
        while (abs(ng - ok) > 1) {
            ll mid = (ok + ng) / 2;
            ll len = mid - ng;
            if (query(ng + 1, mid, 1, N) < len)
                ok = mid;
            else
                ng = mid;
        }
        w = ok;
    }
    {
        ll ng = 0, ok = N;
        while (abs(ng - ok) > 1) {
            ll mid = (ok + ng) / 2;
            ll len = mid - ng;
            if (query(1, N, ng + 1, mid) < len)
                ok = mid;
            else
                ng = mid;
        }
        h = ok;
    }

    result(w, h);

    return 0;
}