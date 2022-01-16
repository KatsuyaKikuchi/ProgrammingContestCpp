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

ll T[10];
ll X[205][205];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, M, R;
    cin >> N >> M >> R;
    vector<ll> r(R);
    REP(i, R) {
        cin >> T[i];
        T[i]--;
        r[i] = i;
    }

    REP(i, N) {
        REP(j, N) {
            X[i][j] = INF;
        }
        X[i][i] = 0;
    }
    REP(i, M) {
        ll a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        X[a][b] = X[b][a] = c;
    }

    REP(k, N) {
        REP(i, N) {
            REP(j, N) {
                X[i][j] = std::min(X[i][j], X[i][k] + X[k][j]);
            }
        }
    }
    REP(k, N) {
        REP(i, N) {
            REP(j, N) {
                X[i][j] = std::min(X[i][j], X[i][k] + X[k][j]);
            }
        }
    }

    ll ans = INF;
    do {
        ll sum = 0;
        REP(i, R - 1) {
            ll a = T[r[i]];
            ll b = T[r[i + 1]];
            sum += X[a][b];
        }
        ans = std::min(ans, sum);
    } while (next_permutation(r.begin(), r.end()));
    cout << ans << endl;
    return 0;
}