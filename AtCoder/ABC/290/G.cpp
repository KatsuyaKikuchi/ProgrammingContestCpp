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

ll solve() {
    ll D, K, X;
    cin >> D >> K >> X;
    ll sum = 0;
    ll d = 0;
    ll ans = 0;
    while (true) {
        d++;
        ll child = sum;
        sum += 1;
        ll t = child * (K - 1);
        if (sum + t < X) {
            sum += t;
            continue;
        }
        ll diff = (sum + t) - X;
        if (d <= D)
            ans++;
        if (diff == 0)
            break;

        while (diff > 0) {
            ll x = diff / child;
            diff -= x * child;
            ans += x;
            child = (child - 1) / K;
        }

        break;
    }
    return ans;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll T;
    cin >> T;
    REP(_, T) {
        cout << solve() << endl;
    }
    return 0;
}