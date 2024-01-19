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
    ll N, M;
    cin >> N >> M;
    N -= 2;
    vector<ll> A(N);
    ll a, b;
    cin >> a >> b;
    REP(i, N) {
        cin >> A[i];
    }
    sort(A.begin(), A.end());
    ll ans = INF;
    REP(i, N) {
        ll last = i + M - 1;
        if (last >= N)
            break;
        ll t = 0;
        t += std::max(0LL, a - A[i]);
        t += std::max(0LL, A[last] - b);
        ans = std::min(ans, t);
    }

    cout << ans << endl;
    return 0;
}