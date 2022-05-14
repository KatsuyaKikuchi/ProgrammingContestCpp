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
    ll N, W;
    cin >> N >> W;
    vector<ll> A(N);
    REP(i, N) {
        cin >> A[i];
    }

    vector<ll> V(W + 5, false);
    REP(i, N) {
        ll n = A[i];
        if (n <= W)
            V[n] = true;
        REP(j, N) {
            if (i == j)
                continue;
            ll m = n + A[j];
            if (m <= W)
                V[m] = true;
            REP(k, N) {
                if (i == k || j == k)
                    continue;
                ll l = m + A[k];
                if (l <= W)
                    V[l] = true;

            }
        }
    }

    ll ans = 0;
    FOR(i, W + 1, 1) {
        if (V[i]) {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}