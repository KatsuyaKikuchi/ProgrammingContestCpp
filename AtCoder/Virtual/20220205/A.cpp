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

ll N, C;
ll D[35][35];
ll A[505][505];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> C;
    REP(i, C) {
        REP(j, C) {
            cin >> D[i][j];
        }
    }
    REP(i, N) {
        REP(j, N) {
            cin >> A[i][j];
            A[i][j]--;
        }
    }

    vector<vector<ll>> X(3, vector<ll>(C, 0));
    REP(c, C) {
        REP(i, N) {
            REP(j, N) {
                ll t = (i + j) % 3;
                X[t][c] += D[A[i][j]][c];
            }
        }
    }
    ll ans = INF;
    REP(a, C) {
        REP(b, C) {
            REP(c, C) {
                if (a == b || b == c || c == a)
                    continue;
                ans = std::min(X[0][a] + X[1][b] + X[2][c], ans);
            }
        }
    }
    cout << ans << endl;
    return 0;
}