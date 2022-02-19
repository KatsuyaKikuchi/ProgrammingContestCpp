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

ll len(pll a, pll b) {
    ll x = a.first - b.first, y = a.second - b.second;
    return x * x + y * y;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    pll a, b;
    cin >> a.first >> a.second >> b.first >> b.second;

    REP(dx, 20) {
        REP(dy, 20) {
            ll x = a.first + dx - 10;
            ll y = a.second + dy - 10;

            ll len0 = len(a, pll(x, y));
            ll len1 = len(b, pll(x, y));

            if (len0 == 5 && len1 == 5) {
                cout << "Yes" << endl;
                return 0;
            }

        }
    }
    cout << "No" << endl;
    return 0;
}