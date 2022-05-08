#include <bits/stdc++.h>

using namespace std;
using ll = long long int;
using pll = pair<ll, ll>;

#define FOR(i, n, m) for(ll i = (m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MAX = 200005;
const ll MOD = 1000000007;
const ll INF = (ll) 1e15;
const long double PI = 3.1415926535897932384626433832795028841971;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    vector<ll> A(N);
    REP(i, N) {
        cin >> A[i];
    }
    sort(A.begin(), A.end());
    vector<ll> S(MAX, 0), T(MAX, 0);

    REP(i, N) {
        T[A[i]]++;
    }

    FOR(i, MAX, 1) {
        ll n = 1;
        while (true) {
            ll m = i * n;
            if (m >= MAX)
                break;
            S[m] += T[i] * T[n];
            n++;
        }
    }

    ll ans = 0;
    REP(i, N) {
        ans += S[A[i]];
    }
#if false
    //ans *= 2;

    ll count = T[1];
    REP(i, N) {
        ll s = T[A[i]];
        ans += count * s * s * 2;
    }
#endif

    cout << ans << endl;
    return 0;
}