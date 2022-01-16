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

double calc(pll a, pll b) {
    double len = pow(a.first - b.first, 2) + pow(a.second - b.second, 2);
    return sqrt(len);
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    vector<pll> A(N);
    REP(i, N) {
        cin >> A[i].first >> A[i].second;
    }
    double ans = 0;
    REP(i, N) {
        REP(j, N) {
            ans = std::max(ans, calc(A[i], A[j]));
        }
    }
    cout << OF64 << ans << endl;
    return 0;
}