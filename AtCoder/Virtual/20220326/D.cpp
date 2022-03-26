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
    vector<ll> A(N);
    vector<ll> X(M);
    REP(i, N) {
        cin >> A[i];
        X[A[i] % M]++;
    }

    ll ans = 0;
    FOR(i, M, 0) {
        ll t = (M - i) % M;
        if (t == i) {
            ans += X[i] / 2;
            X[i] %= 2;
        } else {
            ll x = std::min(X[i], X[t]);
            ans += x;
            X[i] -= x;
            X[t] -= x;
        }
    }


    sort(A.begin(), A.end());
    REP(i, N - 1) {
        if (A[i] != A[i + 1])
            continue;
        ll a = A[i] % M;
        if (X[a] >= 2) {
            ans += 1;
            X[a] -= 2;
            i++;
        }
    }

    cout << ans << endl;
    return 0;
}