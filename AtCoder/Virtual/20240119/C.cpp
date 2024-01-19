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
    ll N, A, B;
    cin >> N >> A >> B;

    ll ans = 0;
    // A<=Bならば常にAlice (N>=A)
    if (A <= B) {
        ans += std::max(0LL, N + 1 - A);
    } else if (N >= A) {
        N -= A - 1;
        ll n = N / A;
        ll m = N % A;
        ans += (B) * n;
        ans += std::min(B, m);
    }
    cout << ans << endl;

    return 0;
}