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

ll X[2][200005][35];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, C;
    cin >> N >> C;

    REP(i, 34) {
        X[0][0][i] = 0;
        X[1][0][i] = 1;
    }

    REP(i, N) {
        ll t, a;
        cin >> t >> a;
        REP(j, 34) {
            ll b = a % 2;
            a /= 2;
            if (t == 1) {
                X[0][i + 1][j] = (X[0][i][j] & b);
                X[1][i + 1][j] = (X[1][i][j] & b);
            } else if (t == 2) {
                X[0][i + 1][j] = (X[0][i][j] | b);
                X[1][i + 1][j] = (X[1][i][j] | b);
            } else {
                X[0][i + 1][j] = (X[0][i][j] ^ b);
                X[1][i + 1][j] = (X[1][i][j] ^ b);
            }
        }
    }

    REP(i, N) {
        ll ret = 0;
        REP(j, 34) {
            ll b = C % 2;
            C /= 2;
            ret += (X[b][i + 1][j] << j);
        }
        cout << ret << endl;
        C = ret;
    }


    return 0;
}