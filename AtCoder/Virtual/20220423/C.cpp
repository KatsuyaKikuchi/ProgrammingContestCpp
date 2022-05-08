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
    ll H, W, M;
    cin >> H >> W >> M;
    vector<pll> A(M);
    REP(i, M) {
        cin >> A[i].first >> A[i].second;
        A[i].first--;
        A[i].second--;
    }

    vector<ll> X(H, W);
    vector<ll> Y(W, H);
    REP(i, M) {
        ll x = A[i].first;
        ll y = A[i].second;
        X[x] = std::min(X[x], y);
        Y[y] = std::min(Y[y], x);
    }

    ll ans = 0;
    vector<ll> S(W + 1, 0);
    REP(x, H) {
        if (Y[0] <= x)
            break;
        ans += X[x];
        S[X[x] + 1] -= 1;
        S[0] += 1;
    }
    cout << ans << endl;

    REP(i, W) {
        S[i + 1] += S[i];
    }

    REP(y, W) {
        if (X[0] <= y)
            break;
        ll t = std::max(Y[y] - S[y], 0LL);
        ans += t;
        cout << t << endl;
    }

    cout << ans << endl;
    return 0;
}