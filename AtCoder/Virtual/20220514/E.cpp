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

bool solve() {
    ll a, s;
    cin >> a >> s;
    ll x = a, y = a;
    if (x + y > s)
        return false;
    ll t = 0;
    while (s > 0) {
        ll sb = s % 2;
        ll xb = x % 2;
        ll tb = (xb * 2 + t) % 2;

        if (tb == sb) {
            t = xb;
        } else {
            if (xb == 1)
                return false;
            if (t == 1)
                t = 1;
            else
                t = 0;
        }

        s /= 2;
        x /= 2;
        y /= 2;
    }
    return t == 0;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll T;
    cin >> T;
    REP(_, T) {
        if (solve())
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}