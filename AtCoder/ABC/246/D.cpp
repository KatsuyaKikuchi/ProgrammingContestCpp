#include <bits/stdc++.h>

using namespace std;
using ll = long long int;
using pll = pair<ll, ll>;

#define FOR(i, n, m) for(ll i = (m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 9e18;
const ll MAX = (ll) 2000000;
const long double PI = 3.1415926535897932384626433832795028841971;

ll calc(ll a, ll b) {
    return a * a * a + a * a * b + a * b * b + b * b * b;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    ll ans = INF;
    REP(a, MAX) {
        ll b = MAX, ng = -1;
        while (abs(b - ng) > 1) {
            ll mid = (b + ng) / 2;
            ll m = calc(a, mid);
            if (m >= N)
                b = mid;
            else
                ng = mid;
        }
        ll n = calc(a, b);
        ans = std::min(ans, n);
    }
    cout << ans << endl;

    return 0;
}