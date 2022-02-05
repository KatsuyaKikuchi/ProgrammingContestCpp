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

bool solve(ll a, ll s) {
    if (a > s)
        return false;
    ll m = 0;
    while (s > 0) {
        ll t = a % 2;
        ll ss = s % 2;

        if (t == 1) {
            ll sum = m;
            m = 1;
            if (sum != ss) {
                return false;
            }
        } else {
            ll sum = m;
            m = 0;
            if (ss != sum) {
                sum++;
                m = sum / 2;
            }
        }

        s /= 2;
        a /= 2;
    }

    return a == 0 && m == 0;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll T;
    cin >> T;
    REP(_, T) {
        ll a, s;
        cin >> a >> s;
        if (solve(a, s))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}