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
    ll N, H;
    cin >> N >> H;
    vector<pll> A(N);
    REP(i, N) {
        cin >> A[i].first >> A[i].second;
    }
    ll mx = 0;
    REP(i, N) {
        mx = std::max(A[i].first, mx);
    }
    ll ans = (H + mx - 1) / mx;
    sort(A.begin(), A.end(), [](pll a, pll b) { return a.second > b.second; });
    REP(i, N) {
        H = std::max(0LL, H - A[i].second);
        ll n = i + 1 + (H + mx - 1) / mx;
        ans = std::min(ans, n);
    }
    cout << ans << endl;
    return 0;
}