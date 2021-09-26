#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <queue>
#include <stack>

using namespace std;
using ll = long long int;
using pll = pair<ll, ll>;

#define FOR(i, n, m) for(ll i = (m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll C[2005][2005][4];

int main() {
    ll H, W;
    cin >> H >> W;
    vector<string> S(H);
    REP(i, H) {
        cin >> S[i];
    }
    memset(C, 0, sizeof(C));
    REP(i, H) {
        ll s = 0;
        REP(j, W) {
            if (S[i][j] == '#')
                s = 0;
            else
                s++;
            C[i][j][0] += s;
        }
    }
    REP(i, H) {
        ll s = 0;
        for (ll j = W - 1; j >= 0; --j) {
            if (S[i][j] == '#')
                s = 0;
            else
                s++;
            C[i][j][1] += s;
        }
    }
    REP(j, W) {
        ll s = 0;
        REP(i, H) {
            if (S[i][j] == '#')
                s = 0;
            else
                s++;
            C[i][j][2] += s;
        }
    }
    REP(j, W) {
        ll s = 0;
        for (ll i = H - 1; i >= 0; --i) {
            if (S[i][j] == '#')
                s = 0;
            else
                s++;
            C[i][j][3] += s;
        }
    }

    ll ans = 0;
    REP(i, H) {
        REP(j, W) {
            ll s = 0;
            REP(k, 4) {
                s += C[i][j][k];
            }
            ans = std::max(ans, s - 3);
        }
    }
    cout << ans << endl;
    return 0;
}