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

ll H, W, A, B;

bool check(vector<vector<ll>> g) {
    ll count = 0;
    REP(i, H) {
        REP(j, W) {
            if (g[i][j] == 1) {
                count++;
                if (i + 1 == H || g[i + 1][j] != 0)
                    return false;
                g[i + 1][j] = 3;
            }
            if (g[i][j] == 2) {
                count++;
                if (j + 1 == W || g[i][j + 1] != 0)
                    return false;
                g[i][j + 1] = 3;
            }
        }
    }
    return count == A;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> H >> W >> A >> B;

    ll ans = 0;
    REP(bit, pow(2, H * W)) {
        vector<vector<ll>> G(H, vector<ll>(W));
        vector<pll> g;
        {
            ll b = bit;
            ll count = 0;
            REP(i, H) {
                REP(j, W) {
                    G[i][j] = (b & 1);
                    b >>= 1;
                    if (G[i][j] == 1) {
                        count++;
                        g.emplace_back(i, j);
                    }
                }
            }
            if (count != A)
                continue;
        }
        REP(bit2, pow(2, A)) {
            ll b = bit2;
            REP(i, A) {
                G[g[i].first][g[i].second] = (b & 1) + 1;
                b >>= 1;
            }
#if false
            REP(i, H) {
                REP(j, W) {
                    cout << G[i][j] << " ";
                }
                cout << endl;
            }
            cout << endl;
#endif

            if (check(G)) {
                ans++;
            }
        }
    }

    cout << ans << endl;

    return 0;
}