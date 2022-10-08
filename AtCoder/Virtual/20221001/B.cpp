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
    ll ret = std::min(B, C);
    B -= ret;
    C -= ret;
    ll c = C / 2;
    ll t0 = std::min(c, A);
    ret += t0;
    C -= t0 * 2;
    A -= t0;
    ll t1 = std::min(B, A / 2);
    ret += t1;
    B -= t1;
    A -= t1 * 2;
    ll t2 = std::min(C, A / 3);
    ret += t2;
    C -= t2;
    A -= t2 * 3;
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