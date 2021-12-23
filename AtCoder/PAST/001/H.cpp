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

ll C[200005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    pll mn(INF, INF);
    REP(i, N) {
        cin >> C[i];
        if (i % 2 == 0)
            mn.first = std::min(mn.first, C[i]);
        else
            mn.second = std::min(mn.second, C[i]);
    }
    ll Q;
    cin >> Q;
    ll ans = 0;
    pll d(0, 0);
    REP(_, Q) {
        ll t, x, a;
        cin >> t;
        switch (t) {
            case 1: {
                cin >> x >> a;
                x--;
                ll n = C[x] - (a + d.first);
                if (x % 2 == 0)
                    n -= d.second;
                if (n >= 0) {
                    ans += a;
                    C[x] -= a;
                }
                if (x % 2 == 0) {
                    mn.first = std::min(mn.first, C[x]);
                } else {
                    mn.second = std::min(mn.second, C[x]);
                }
                break;
            }
            case 2: {
                cin >> a;
                if (mn.first - (a + d.first + d.second) >= 0) {
                    ans += a * ((N + 1) / 2);
                    d.second += a;
                }
                break;
            }
            case 3: {
                cin >> a;
                if (mn.first - (a + d.first + d.second) >= 0 &&
                    mn.second - (a + d.first) >= 0) {
                    ans += N * a;
                    d.first += a;
                }
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}