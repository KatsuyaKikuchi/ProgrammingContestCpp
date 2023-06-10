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
    ll X, K, D;
    cin >> X >> K >> D;
    ll ans = INF;
    if (X < 0) {
        ll k = abs(X) / D;
        if (k > K) {
            ans = abs(X + K * D);
        } else {
            X += k * D;
            K -= k;
            if (K % 2 == 0)
                ans = abs(X);
            else
                ans = abs(X + D);
        }
    } else {
        ll k = abs(X) / D;
        if (k > K) {
            ans = abs(X - K * D);
        } else {
            X -= k * D;
            K -= k;
            if (K % 2 == 0)
                ans = abs(X);
            else
                ans = abs(X - D);
        }
    }
    cout << ans << endl;
    return 0;
}