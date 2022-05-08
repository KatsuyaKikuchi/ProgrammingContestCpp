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

ll A[305][305];
ll B[305][305];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    REP(i, N) {
        REP(j, N) {
            cin >> A[i][j];
        }
    }

    REP(i, N) {
        REP(j, N) {
            B[i][j] = INF;
        }
        B[i][i] = 0;
    }

    REP(k, N) {
        REP(i, N) {
            REP(j, N) {
                B[i][j] = std::min(B[i][j], A[i][k] + A[k][j]);
            }
        }
    }
    REP(k, N) {
        REP(i, N) {
            REP(j, N) {
                B[i][j] = std::min(B[i][j], A[i][k] + A[k][j]);
            }
        }
    }

    ll ans = 0;
    REP(i, N) {
        FOR(j, N, i + 1) {
            bool e = true;
            REP(k, N) {
                if (k == i || k == j)
                    continue;
                if (B[i][j] == B[i][k] + B[k][j])
                    e = false;
            }
            if (e)
                ans += B[i][j];
        }
    }

    REP(i, N) {
        REP(j, N) {
            if (A[i][j] != B[i][j])
                ans = -1;
        }
    }

    cout << ans << endl;

    return 0;
}