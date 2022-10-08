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

ll x[4] = {1, 0, -1, 0};
ll y[4] = {0, 1, 0, -1};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll H, W;
    cin >> H >> W;
    vector<string> S(H);
    REP(i, H) {
        cin >> S[i];
    }
    vector<vector<ll>> M(H, vector<ll>(W, INF));
    queue<pll> q;
    REP(i, H) {
        REP(j, W) {
            if (S[i][j] == '#') {
                M[i][j] = 0;
                q.push(pll(i, j));
            }
        }
    }

    while (!q.empty()) {
        pll t = q.front();
        q.pop();
        ll c = M[t.first][t.second] + 1;
        REP(i, 4) {
            ll nx = x[i] + t.first, ny = y[i] + t.second;
            if (nx < 0 || ny < 0 || nx >= H || ny >= W)
                continue;
            if (M[nx][ny] <= c)
                continue;
            M[nx][ny] = c;
            q.push(pll(nx, ny));
        }

    }

    ll ans = 0;
    REP(i, H) {
        REP(j, W) {
            ans = std::max(M[i][j], ans);
        }
    }
    cout << ans << endl;
    return 0;
}