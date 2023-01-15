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
    ll N;
    cin >> N;
    ll ans = 0;
    REP(i, 16) {
        ll n = 0;
        REP(j, i + 1) {
            n = n * 10 + 1;
        }

        ll count = 1;
        while (n <= N) {
            ll m = (n / 10);
            if (N < m) {
                ans += count - 1;
            } else {

            }
            n *= 10LL;
            count *= 10LL;
        }
    }
    cout << ans << endl;
    return 0;
}