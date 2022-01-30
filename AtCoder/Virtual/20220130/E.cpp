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

struct Data {
    ll s;
    pll r;
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, M;
    cin >> N >> M;
    vector<Data> D(N);
    REP(i, N) {
        cin >> D[i].r.first >> D[i].r.second >> D[i].s;
        D[i].r.first--;
        D[i].r.second--;
    }
    vector<ll> L(M + 5, 0);
    vector<ll> R(M + 5, 0);
    REP(i, N) {
        ll left = D[i].r.second;
        L[left] += D[i].s;
        ll right = D[i].r.first;
        R[right] += D[i].s;
    }
    REP(i, M) {
        L[i + 1] += L[i];
    }
    for (ll i = M; i >= 0; --i) {
        R[i] += R[i + 1];
    }

    ll ans = 0;
    REP(i, M) {
        ll s = R[i + 1];
        if (i > 0)
            s += L[i - 1];
        ans = std::max(ans, s);
    }
    cout << ans << endl;

    return 0;
}