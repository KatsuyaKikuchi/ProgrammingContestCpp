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
    vector<ll> A(N);
    REP(i, N) {
        cin >> A[i];
    }

    vector<ll> S(N + 5, 0);
    {
        ll s = 0;
        ll index = 0;
        REP(i, N + 1) {
            S[i] = s;
            s += A[index / 2];
            index++;
        }
    }
    vector<ll> L(N + 5, -INF);
    L[0] = 0;
    REP(i, N) {
        for (ll j = i - 1; j >= 0; --j) {
            ll d = (i - 1) - j;
            L[i] = std::max(L[i], L[j] + S[d]);
        }
    }

    ll ans = 0;
    REP(i, N) {
        FOR(j, N, i) {
            ll d = i + N - 1 - j;
            ll s = L[j - i] + S[d];
            ans = std::max(ans, s);
        }
    }
    cout << ans << endl;
    return 0;
}