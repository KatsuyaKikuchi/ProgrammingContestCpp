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
    ll A, B, C;
    cin >> A >> B >> C;

    B = B / 2;

    ll ret = std::min(C, B);
    C -= ret;
    B -= ret;

    if (B > 0) {
        ll m = std::min(B, A / 2);
        A -= m * 2;
        ret += m;
    } else if (C > 0) {
        ll n = C / 2;
        ll m = std::min(n, A);
        ret += m;
        A -= m;
        C -= m * 2;
        if (C > 0)
            A += 2;
    }
    ret += A / 5;
    return ret;
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