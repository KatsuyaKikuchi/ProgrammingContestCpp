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
        cin >> A[i].first >> A[i].second;
    }
    sort(A.begin(), A.end(), [](pll a, pll b) { return a.first + a.second > b.first + b.second; });
    ll ans = 0;
    REP(i, N) {
        if (i % 2 == 0)
            ans += A[i].first;
        else
            ans -= A[i].second;
    }
    cout << ans << endl;
    return 0;
}