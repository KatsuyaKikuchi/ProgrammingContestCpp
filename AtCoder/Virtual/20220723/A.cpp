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

ll N, a, b;
vector<ll> A;

bool check(ll m) {
    ll ta = 0;
    ll tb = 0;
    REP(i, N) {
        if (A[i] >= m) {
            tb += (A[i] - m) / b;
        } else {
            ta += (m - A[i] + a - 1) / a;
        }
    }
    return tb >= ta;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> N >> a >> b;
    A.resize(N);
    REP(i, N) {
        cin >> A[i];
    }

    ll ans = 0, ng = INF;
    while (abs(ans - ng) > 1) {
        ll mid = (ans + ng) / 2;
        if (check(mid))
            ans = mid;
        else
            ng = mid;
    }
    cout << ans << endl;
    return 0;
}