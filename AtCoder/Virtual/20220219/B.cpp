#include <bits/stdc++.h>

using namespace std;
using ll = long long int;
using pll = pair<ll, ll>;

#define FOR(i, n, m) for(ll i = (m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll MAX = 2005;
const ll INF = (ll) 1e15;
const long double PI = 3.1415926535897932384626433832795028841971;

string S[MAX];
ll D[MAX][MAX];

ll x[4] = {0, 1, 0, -1};
ll y[4] = {1, 0, -1, 0};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll H, W;
    cin >> H >> W;
    REP(i, H) {
        cin >> S[i];
    }
    pll s, g;
    vector<vector<pll>> T(30);
    REP(i, H) {
        REP(j, W) {
            if (S[i][j] == '.' || S[i][j] == '#')
                continue;
            if (S[i][j] == 'S')
                s = pll(i, j);
            else if (S[i][j] == 'G')
                g = pll(i, j);
            else
                T[S[i][j] - 'a'].push_back(pll(i, j));
        }
    }
    REP(i, MAX) {
        REP(j, MAX) {
            D[i][j] = INF;
        }
    }

    queue<pll> q;
    q.push(s);
    D[s.first][s.second] = 0;

    while (!q.empty()) {
        pll t = q.front();
        q.pop();
        ll cost = D[t.first][t.second] + 1;

        bool warp = t.first == MAX - 1;
        if (warp) {
            cost--;
            ll index = t.second;
            for (auto nxt: T[index]) {
                if (D[nxt.first][nxt.second] <= cost)
                    continue;
                D[nxt.first][nxt.second] = cost;
                q.push(nxt);
            }
        } else {
            REP(i, 4) {
                ll nx = x[i] + t.first, ny = y[i] + t.second;
                if (nx < 0 || nx >= H || ny < 0 || ny >= W)
                    continue;
                if (S[nx][ny] == '#' || D[nx][ny] <= cost)
                    continue;
                D[nx][ny] = cost;
                q.push(pll(nx, ny));
            }
            char c = S[t.first][t.second];
            if ('a' <= c & c <= 'z') {
                ll nx = MAX - 1, ny = c - 'a';
                if (D[nx][ny] > cost) {
                    D[nx][ny] = cost;
                    q.push(pll(nx, ny));
                }
            }
        }
    }

    ll ans = D[g.first][g.second];
    if (ans == INF)
        ans = -1;
    cout << ans << endl;

    return 0;
}