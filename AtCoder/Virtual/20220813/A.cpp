
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

    ll N, L, R;
    cin >> N >> L >> R;
    vector<ll> A(N);
    ll ans = 0;
    REP(i, N) {
        cin >> A[i];
        ans += A[i];
    }

    vector<ll> v(N + 1, ans);
    ll s = 0;
    REP(y, N) {
        s += A[N - 1 - y];
        v[N - 1 - y] = std::min(v[N - y], ans - s + (y + 1) * R);
    }
    s = 0;
    REP(x, N) {
        s += A[x];
        ans = std::min(ans, (x + 1) * L + v[x + 1] - s);
    }

    cout << std::min({ans, N * R, N * L, v[0]}) << endl;

    return 0;
}