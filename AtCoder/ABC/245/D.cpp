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
    vector<ll> A(N + 1);
    vector<ll> C(N + M + 1);
    REP(i, A.size()) {
        cin >> A[i];
    }
    REP(i, C.size()) {
        cin >> C[i];
    }

    vector<ll> B(M + 1, INF);
    REP(i, B.size()) {
        ll x = C[N + M - i];
        REP(j, i) {
            ll index = N + M - i - M + j;
            if (index >= 0)
                x -= B[M - j] * A[index];
        }
        B[M - i] = x / A[N];
    }

    REP(i, B.size()) {
        cout << B[i] << " ";
    }
    cout << endl;
    return 0;
}