#include <bits/stdc++.h>

using namespace std;
using ll = long long int;
using pll = pair<ll, ll>;

#define FOR(i, n, m) for(ll i = (m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e10;
const long double PI = 3.1415926535897932384626433832795028841971;

ll N, A, B;
vector<ll> H;

bool check(ll x) {
    ll count = 0;
    ll d = A - B;
    REP(i, N) {
        ll h = H[i] - B * x;
        if (h > 0)
            count += (d - 1 + h) / d;
    }
    return count <= x;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> A >> B;
    H.resize(N);
    REP(i, N) {
        cin >> H[i];
    }

    ll ans = INF, ng = 0;
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