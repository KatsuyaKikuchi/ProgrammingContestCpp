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
    vector<ll> A(N);
    vector<ll> C(1000005, 0);
    REP(i, N) {
        cin >> A[i];
        C[A[i]]++;
    }

    sort(A.begin(), A.end());
    vector<bool> D(1000005, false);
    vector<bool> U(1000005, false);

    ll ans = 0;
    REP(i, N) {
        if (!D[A[i]] && C[A[i]] == 1)
            ans++;
        if (U[A[i]])
            continue;
        U[A[i]] = true;
        for (ll j = A[i]; j < D.size(); j += A[i]) {
            D[j] = true;
        }
    }
    cout << ans << endl;
    return 0;
}