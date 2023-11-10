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

    vector<ll> S(N + 5, 0), I(N + 5, -1), C(N + 5, 0);
    ll ans = 0;
    REP(i, N) {
        ll n = A[i];
        ll d = i - I[n] - 1;
        S[n] += C[n] * d;
        ans += S[n];
        I[n] = i;
        C[n]++;
    }
    cout << ans << endl;
    return 0;
}