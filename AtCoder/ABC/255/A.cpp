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

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll R, C;
    cin >> R >> C;
    ll ans = 0;
    REP(i, 2) {
        REP(j, 2) {
            ll a;
            cin >> a;
            if (i + 1 == R && j + 1 == C)
                ans = a;
        }
    }
    cout << ans << endl;
    return 0;
}