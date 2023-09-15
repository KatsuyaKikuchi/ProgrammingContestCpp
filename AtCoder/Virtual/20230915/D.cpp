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

ll A[105][105][2];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll H, W;
    cin >> H >> W;
    vector<string> S(H);
    REP(i, H) {
        cin >> S[i];
    }

    REP(i, H) {
        REP(j, W) {
            A[i][j][0] = A[i][j][1] = INF;
        }
    }

    if (S[0][0] == '.') {
        A[0][0][0] = 0;
    } else {
        A[0][0][1] = 1;
    }

    REP(i, H) {
        REP(j, W) {
            if (i > 0) {
                if (S[i][j] == '.') {
                    A[i][j][0] = std::min({A[i][j][0], A[i - 1][j][0], A[i - 1][j][1]});
                } else {
                    A[i][j][1] = std::min({A[i][j][1], A[i - 1][j][0] + 1, A[i - 1][j][1]});
                }
            }
            if (j > 0) {
                if (S[i][j] == '.') {
                    A[i][j][0] = std::min({A[i][j][0], A[i][j - 1][0], A[i][j - 1][1]});
                } else {
                    A[i][j][1] = std::min({A[i][j][1], A[i][j - 1][0] + 1, A[i][j - 1][1]});
                }
            }
        }
    }

    cout << std::min(A[H - 1][W - 1][0], A[H - 1][W - 1][1]) << endl;

    return 0;
}