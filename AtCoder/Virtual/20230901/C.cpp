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
char C[4] = {'>', 'v', '<', '^'};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll H, W;
    cin >> H >> W;
    vector<string> S(H);
    REP(i, H) {
        cin >> S[i];
    }
    vector<vector<ll> > D(H, vector<ll>(W, INF));
    pll s, g;
    REP(i, H) {
        REP(j, W) {
            if (S[i][j] == 'S')s = pll(i, j);
            if (S[i][j] == 'G')g = pll(i, j);
        }
    }

    vector<string> T(H);
    REP(i, H) {
        REP(j, W) {
            T[i].push_back(S[i][j]);
        }
    }
    {
        REP(i, H) {
            bool e = false;
            REP(j, W) {
                if (S[i][j] != '.')
                    e = false;
                if (S[i][j] == '>')
                    e = true;
                if (e)
                    T[i][j] = '#';
            }
        }
    }
    {
        REP(i, H) {
            bool e = false;
            for (ll j = W - 1; j >= 0; --j) {
                if (S[i][j] != '.')
                    e = false;
                if (S[i][j] == '<')
                    e = true;
                if (e)
                    T[i][j] = '#';
            }
        }
    }
    {
        REP(j, W) {
            bool e = false;
            REP(i, H) {
                if (S[i][j] != '.')
                    e = false;
                if (S[i][j] == 'v')
                    e = true;
                if (e)
                    T[i][j] = '#';
            }
        }
    }
    {
        REP(j, W) {
            bool e = false;
            for (ll i = H - 1; i >= 0; --i) {
                if (S[i][j] != '.')
                    e = false;
                if (S[i][j] == '^')
                    e = true;
                if (e)
                    T[i][j] = '#';
            }
        }
    }
    REP(i, H) {
        REP(j, W) {
            if (T[i][j] != '.' && T[i][j] != 'S' && T[i][j] != 'G')
                T[i][j] = '#';
        }
    }

    REP(i, H) {
        // cout << T[i] << endl;
    }

    queue<pll> q;
    q.push(s);
    D[s.first][s.second] = 0;
    while (!q.empty()) {
        pll t = q.front();
        q.pop();
        ll cost = D[t.first][t.second] + 1;
        REP(i, 4) {
            ll nx = x[i] + t.first, ny = y[i] + t.second;
            if (nx < 0 || nx >= H || ny < 0 || ny >= W)
                continue;
            if (D[nx][ny] <= cost)
                continue;
            if (T[nx][ny] == '#')
                continue;
            D[nx][ny] = cost;
            q.push(pll(nx, ny));
        }
    }

    ll ans = D[g.first][g.second];
    if (ans == INF)ans = -1;
    cout << ans << endl;
    return 0;
}