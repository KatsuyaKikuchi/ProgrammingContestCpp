#include <bits/stdc++.h>

using namespace std;
using ll = long long int;
using pll = pair<ll, ll>;

#define FOR(i, n, m) for(ll i = (m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MAX = 100005;
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
    vector<ll> t0(MAX, 0), t1(MAX, 0);
    for (ll i = 0; i < N; i += 2) {
        t0[A[i]]++;
    }
    for (ll i = 1; i < N; i += 2) {
        t1[A[i]]++;
    }
    ll t0m = 0, t1m = 0;
    REP(i, MAX) {
        if (t0[t0m] < t0[i])
            t0m = i;
        if (t1[t1m] < t1[i])
            t1m = i;
    }
    ll ans = INF;
    if (t0m == t1m) {
        ll t0s = MAX - 1, t1s = MAX - 1;
        REP(i, MAX) {
            if (i != t0m && t0[t0s] < t0[i])
                t0s = i;
            if (i != t1m && t1[t1s] < t1[i])
                t1s = i;
        }
        ans = std::min((N + 1) / 2 - t0[t0m] + N / 2 - t1[t1s],
                       (N + 1) / 2 - t0[t0s] + N / 2 - t1[t1m]);
    } else {
        ans = (N + 1) / 2 - t0[t0m] + N / 2 - t1[t1m];
    }
    cout << ans << endl;
    return 0;
}