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

ll N;
vector<string> S;
ll x[8] = {0, 1, 1, 1, 0, -1, -1, -1};
ll y[8] = {1, 1, 0, -1, -1, -1, 0, 1};

ll solve(pll s, ll dir) {
    ll ret = S[s.first][s.second] - '0';
    REP(i, N - 1) {
        ll nx = (x[dir] + s.first + 2 * N) % N;
        ll ny = (y[dir] + s.second + 2 * N) % N;
        s = pll(nx, ny);
        ret = ret * 10 + S[s.first][s.second] - '0';
    }
    return ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    S.resize(N);
    REP(i, N) {
        cin >> S[i];
    }

    ll ans = 0;
    REP(i, N) {
        REP(j, N) {
            REP(d, 8) {
                ans = std::max(ans, solve(pll(i, j), d));
            }
        }
    }
    cout << ans << endl;
    return 0;
}