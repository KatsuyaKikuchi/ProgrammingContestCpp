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

ll N;
vector<ll> A;

ll solve() {
    ll n = 1;
    vector<ll> M(N + 5, 1);
    REP(i, N + 1) {
        n -= A[i];
        if (n < 0)
            return -1;
        n = std::min(n * 2LL, INF);
        M[i + 1] = n;
    }
    ll ret = 0;
    ll p = 0;
    for (ll i = N; i >= 0; --i) {
        p = std::min(M[i], p + A[i]);
        ret += p;
    }
    return ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> N;
    A.resize(N + 1);
    REP(i, N + 1) {
        cin >> A[i];
    }

    cout << solve() << endl;

    return 0;
}