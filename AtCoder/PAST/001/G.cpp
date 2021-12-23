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

ll A[15][15];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    REP(i, N - 1) {
        FOR(j, N, i + 1) {
            cin >> A[i][j];
            A[j][i] = A[i][j];
        }
    }

    ll ans = -INF;
    REP(b, pow(3LL, N)) {
        ll sum = 0;
        ll bit = b;
        vector<ll> g[3];
        REP(i, N) {
            g[(bit % 3)].push_back(i);
            bit /= 3;
        }
        REP(i, 3) {
            REP(j, g[i].size()) {
                FOR(k, g[i].size(), j + 1) {
                    ll a = g[i][j];
                    ll b = g[i][k];
                    sum += A[a][b];
                }
            }
        }
        ans = std::max(ans, sum);
    }
    cout << ans << endl;
    return 0;
}