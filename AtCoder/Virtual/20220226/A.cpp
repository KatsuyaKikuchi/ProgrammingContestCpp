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
    vector<ll> S(N);
    REP(i, N) {
        cin >> S[i];
    }

    vector<ll> A(N + 2, 0);
    REP(i, N - 1) {
        ll d = S[i + 1] - S[i];
        A[i + 3] = A[i] + d;
    }
    vector<ll> B(3, 0);
    for (ll i = 0; i < A.size(); i += 3) {
        REP(j, 3) {
            if (i + j < A.size())
                B[j] = std::min(B[j], A[i + j]);
        }
    }
    for (ll i = 0; i < A.size(); i += 3) {
        REP(j, 3) {
            if (i + j < A.size())
                A[i + j] -= B[j];
        }
    }

    ll diff = S[0] - (A[0] + A[1] + A[2]);
    REP(i, N) {
        ll s = A[i] + A[i + 1] + A[i + 2];
        if (diff != S[i] - s) {
            cout << "No" << endl;
            return 0;
        }
    }
    if (diff < 0) {
        cout << "No" << endl;
        return 0;
    }

    cout << "Yes" << endl;
    REP(i, A.size()) {
        if (i % 3 == 0)A[i] += diff;
        cout << A[i] << " ";
    }
    cout << endl;
    return 0;
}