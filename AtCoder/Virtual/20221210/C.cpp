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
    vector<pll> A(N);
    REP(i, N) {
        cin >> A[i].first;
    }
    REP(i, N) {
        cin >> A[i].second;
    }
    sort(A.begin(), A.end(), [](pll a, pll b) { return a.first < b.first; });
    ll ans = N;

    vector<ll> t(N + 5, INF);
    REP(i, N) {
        ll x = lower_bound(t.begin(), t.end(), A[i].second) - t.begin();
        t[x] = A[i].second;
    }
    ll index = lower_bound(t.begin(), t.end(), INF) - t.begin();

    cout << ans + index << endl;
    return 0;
}