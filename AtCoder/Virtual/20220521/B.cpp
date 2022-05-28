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
    ll N;
    cin >> N;
    vector<ll> T(N), A(N);
    REP(i, N) {
        cin >> T[i];
    }
    REP(i, N) {
        cin >> A[i];
    }
    vector<ll> F(N, false);
    F[0] = true;
    FOR(i, N, 1) {
        if (T[i] > T[i - 1])
            F[i] = true;
    }
    ll ans = 1;
    ll s = -1;
    for (ll i = N - 1; i >= 0; --i) {
        if (A[i] != s) {
            if (F[i] && T[i] != A[i])
                ans = 0;
            s = A[i];
            if (s > T[i])
                ans = 0;
        } else {
            if (!F[i]) {
                ans *= std::min(A[i], T[i]);
                ans %= MOD;
            }
        }
    }
    cout << ans << endl;
    return 0;
}