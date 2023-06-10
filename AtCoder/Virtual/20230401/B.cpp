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

ll x[4] = {0, 1, 0, -1};
ll y[4] = {1, 0, -1, 0};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll H, W;
    cin >> H >> W;
    vector<string> S(H);
    REP(i, H) {
        cin >> S[i];
    }

    ll ans = 0;
    std::set<pll> s;
    REP(i, H) {
        REP(j, W) {
            if (S[i][j] == '.')
                continue;
            s.insert(pll(i, j));
        }
    }
    while (!s.empty()) {
        std::set<pll> tmp;
        for (auto t: s) {
            REP(i, 4) {
                ll nx = t.first + x[i], ny = t.second + y[i];
                if (nx < 0 || ny < 0 || nx >= H || ny >= W)
                    continue;
                if (S[nx][ny] == '#')
                    continue;
                S[nx][ny] = '#';
                tmp.insert(pll(nx, ny));
            }
        }
        swap(s, tmp);
        ans++;
    }
    cout << ans - 1 << endl;
    return 0;
}