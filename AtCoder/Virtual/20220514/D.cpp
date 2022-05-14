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
    ll N, K;
    cin >> N >> K;
    vector<ll> A(N);
    REP(i, N) {
        cin >> A[i];
    }

    vector<ll> C(N, 0);
    vector<ll> P(N, 0);
    REP(i, N) {
        REP(j, i) {
            if (A[j] > A[i])
                C[i]++;
        }
        REP(j, N) {
            if (A[j] > A[i])
                P[i]++;
        }
    }

    ll ans = 0;
    REP(i, N) {
        ll s = (C[i] * K) % MOD;
        ll n = (K * (K - 1)) / 2;
        n %= MOD;
        s += P[i] * n;
        ans += s % MOD;
        ans %= MOD;
    }
    cout << ans << endl;
    return 0;
}