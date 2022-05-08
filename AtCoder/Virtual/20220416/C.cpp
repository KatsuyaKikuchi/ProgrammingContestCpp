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

ll N, K;
ll x[4] = {0, 1, 0, -1};
ll y[4] = {1, 0, -1, 0};

ll dfs(pll g, vector<string> &S, ll count = 0) {
    if (count == K)
        return 1;
    ll ret = 0;
    S[g.first][g.second] = '#';
    REP(i, 4) {
        ll nx = x[i] + g.first, ny = y[i] + g.second;
        if (nx < 0 || ny < 0 || nx >= N || ny >= N)
            continue;
        if (S[nx][ny] == '#')
            continue;
        ret += dfs(pll(nx, ny), S, count + 1);
    }
    S[g.first][g.second] = '.';
    return ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> K;
    vector<string> S(N);
    REP(i, N) {
        cin >> S[i];
    }

    ll ans = 0;
    REP(i, N) {
        REP(j, N) {
            if (S[i][j] == '#')
                continue;
            ans += dfs(pll(i, j), S);
            S[i][j] = '#';
        }
    }
    cout << ans << endl;
    return 0;
}