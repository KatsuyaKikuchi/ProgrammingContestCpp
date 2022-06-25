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
    ll N, Q, K;
    cin >> N >> K >> Q;
    vector<ll> A(K);
    vector<ll> L(Q);
    REP(i, K) {
        cin >> A[i];
    }
    REP(i, Q) {
        cin >> L[i];
        ll t = L[i] - 1;
        if (A[t] == N)
            continue;
        A[t]++;
        if (t + 1 < K && A[t + 1] == A[t])
            A[t]--;
    }

    // sort(A.begin(), A.end(), [](pll a, pll b) { return a.second < b.second; });
    REP(i, K) {
        cout << A[i] << " ";
    }
    cout << endl;
    return 0;
}