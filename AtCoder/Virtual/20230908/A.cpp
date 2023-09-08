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
    ll N, M;
    cin >> N >> M;
    vector<ll> A(N), B(M);
    REP(i, N) {
        cin >> A[i];
    }
    REP(i, M) {
        cin >> B[i];
    }

    ll t = A[0] == 0 ? 1 : 0;
    ll m = INF;
    REP(i, N) {
        if (t == A[i])
            m = std::min(m, i);
        if (t == A[N - 1 - i])
            m = std::min(m, i + 1);
    }

    ll ans = 0;
    ll x = A[0];
    REP(i, M) {
        if (x != B[i]) {
            ans += m;
            m = 1;
            x = B[i];
        }
        ans++;
    }

    if (ans >= INF)
        ans = -1;
    cout << ans << endl;

    return 0;
}