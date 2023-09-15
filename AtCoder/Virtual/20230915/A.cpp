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
    ll b = B / 2;
    ll ret = 0;
    ret += std::min(b, C);
    C -= ret;
    b -= ret;
    if (b == 0) {
        ll c = C / 2;
        ll n0 = std::min(A, c);
        A -= n0;
        ret += n0;
        C -= n0 * 2LL;
        ll n1 = std::min(C, A / 3);
        A -= n1 * 3LL;
        ret += n1;
    } else if (C == 0) {
        ll n0 = std::min(b, A / 2);
        A -= 2LL * n0;
        ret += n0;
    }

    return ret + (A / 5);
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