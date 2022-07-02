#include <bits/stdc++.h>

using namespace std;
using ll = long long int;
using pll = pair<ll, ll>;

#define FOR(i, n, m) for(ll i = (m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 2e18 + 10;
const long double PI = 3.1415926535897932384626433832795028841971;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, X;
    cin >> N >> X;
    vector<pll> A(N);
    REP(i, N) {
        cin >> A[i].first >> A[i].second;
    }
    ll ans = INF;
    ll s = 0;
    ll mn = INF;
    REP(i, N) {
        s += A[i].first + A[i].second;
        mn = std::min(mn, A[i].second);
        ll x = X - (i + 1);

        ans = std::min(ans, s + x * mn);
    }
    cout << ans << endl;
    return 0;
}