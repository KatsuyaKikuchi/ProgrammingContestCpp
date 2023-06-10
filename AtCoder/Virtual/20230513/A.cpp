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

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll H, W, K;
    cin >> H >> W >> K;
    vector<string> S(H);
    REP(i, H) {
        cin >> S[i];
    }
    vector<vector<ll>> ans(H, vector<ll>(W, 0));
    ll k = 0;
    REP(i, H) {
        bool f = false;
        REP(j, W) {
            if (S[i][j] == '#') {
                k++;
                f = true;
            }
            if (f)
                ans[i][j] = k;
        }
        ll n = 0;
        for (ll j = W - 1; j >= 0; --j) {
            if (ans[i][j] > 0)
                n = ans[i][j];
            ans[i][j] = n;
        }
    }

    REP(j, W) {
        ll n = 0;
        REP(i, H) {
            if (ans[i][j] > 0)
                n = ans[i][j];
            ans[i][j] = n;
        }
        n = 0;
        for (ll i = H - 1; i >= 0; --i) {
            if (ans[i][j] > 0)
                n = ans[i][j];
            ans[i][j] = n;
        }
    }

    REP(i, H) {
        REP(j, W) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}