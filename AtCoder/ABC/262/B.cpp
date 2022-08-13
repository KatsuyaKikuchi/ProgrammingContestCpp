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

bool D[105][105];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, M;
    cin >> N >> M;
    memset(D, 0, sizeof(D));
    REP(i, M) {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        D[a][b] = D[b][a] = true;
    }

    ll ans = 0;
    REP(i, N) {
        REP(j, i) {
            if (!D[i][j])
                continue;
            REP(k, j) {
                if (D[i][k] && D[j][k])
                    ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}