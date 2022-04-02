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
    ll N, K, X;
    cin >> N >> K >> X;
    vector<ll> A(N);
    REP(i, N) {
        cin >> A[i];
    }
    REP(i, N) {
        ll n = A[i] / X;
        ll d = std::min(K, n);
        K -= d;
        A[i] -= d * X;
    }

    sort(A.begin(), A.end(), greater<ll>());
    ll ans = 0;
    REP(i, N) {
        ll n = (A[i] + X - 1) / X;
        ll d = std::min(n, K);
        K -= d;
        A[i] = std::max(0LL, A[i] - d * X);
        ans += A[i];
    }
    cout << ans << endl;
    return 0;
}