#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
using ll = long long int;
using pll = pair<ll, ll>;

#define FOR(i, n, m) for(ll i = (m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)

const ll INF = (ll) 1e15;
const ll MOD = 1000000007;

ll S[1000][2005];

int main() {
    ll N;
    cin >> N;
    memset(S, 0, sizeof(S));
    S[0][0] = 1;
    ll len = N / 3 + 1;
    REP(i, len) {
        FOR(n, N + 1, 3) {
            REP(j, N) {
                if (j + n > N)break;
                S[i + 1][j + n] += S[i][j];
                S[i + 1][j + n] %= MOD;
            }
        }
    }

    ll ans = 0;
    FOR(i, len + 1, 1) {
        ans = (ans + S[i][N]) % MOD;
    }
    cout << ans << endl;
    return 0;
}