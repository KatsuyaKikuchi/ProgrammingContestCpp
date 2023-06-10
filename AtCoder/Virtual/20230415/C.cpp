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

ll H, W;

ll solve(const vector<string> &S, pll s, pll g) {
    vector<vector<ll>> C(H, vector<ll>(W, INF));
    C[s.first][s.second] = 0;
    queue<pll> q;
    q.push(s);
    while (!q.empty()) {
        pll t = q.front();
        q.pop();
        ll cost = C[t.first][t.second] + 1;
        REP(i, 4) {
            ll nx = x[i] + t.first, ny = y[i] + t.second;
            if (nx < 0 || ny < 0 || nx >= H || ny >= W)
                continue;
            if (S[nx][ny] == '#')
                continue;
            if (C[nx][ny] <= cost)
                continue;
            C[nx][ny] = cost;
            q.push(pll(nx, ny));
        }
    }
    return C[g.first][g.second];
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> H >> W;
    vector<string> S(H);
    REP(i, H) {
        cin >> S[i];
    }
    ll ans = 0;
    vector<pll> start, goal;
    REP(i, H) {
        REP(j, W) {
            if (S[i][j] == '#')
                continue;
            start.push_back(pll(i, j));
            goal.push_back(pll(i, j));
        }
    }

    for (auto s: start) {
        for (auto g: goal) {
            ans = std::max(ans, solve(S, s, g));
        }
    }
    cout << ans << endl;

    return 0;
}