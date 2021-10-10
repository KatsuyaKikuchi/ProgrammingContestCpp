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

struct Vertex {
    vector<pll> node;
};
struct Data {
    ll to;
    ll cost;
    ll max;
};

ll dp[405][405][405];
ll dp2[405][405][405];

int main() {
    ll N, M;
    cin >> N >> M;
    vector<Vertex> V(N);
    REP(i, M) {
        ll a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        V[a].node.push_back(pll(b, c));
    }

    REP(i, N) {
        REP(j, N) {
            REP(k, N) {
                dp[i][j][k] = INF;
                dp2[i][j][k] = INF;
            }
        }
    }
    REP(i, N) {
        REP(j, N) {
            dp[i][i][j] = 0;
            dp2[i][i][j] = 0;
        }
    }

    REP(i, N) {
        priority_queue<Data, vector<Data>, function<bool(Data, Data)>> q(
                [](Data a, Data b) { return a.cost > b.cost; });
        q.push(Data{i, 0, 0});
        while (!q.empty()) {
            auto t = q.top();
            q.pop();
            if (dp[i][t.to][t.max] < t.cost)
                continue;
            for (auto &nxt: V[t.to].node) {
                ll n = nxt.first;
                ll cost = nxt.second + t.cost;
                ll mx = std::max(n, t.max);
                dp2[i][n][t.max] = std::min(dp2[i][n][t.max], cost);
                if (dp[i][n][mx] <= cost)
                    continue;
#if true
                for (ll j = mx; j < N; ++j) {
                    if (dp[i][n][j] <= cost)
                        break;
                    dp[i][n][j] = cost;
                }
#else
                dp[i][n][mx] = cost;
#endif
                q.push(Data{n, cost, mx});
            }
        }
    }
    REP(i, N) {
        REP(j, N) {
            ll mn = dp2[i][j][0];
            REP(k, N) {
                mn = std::min(mn, dp2[i][j][k]);
                dp2[i][j][k] = mn;
            }
        }
    }

    ll ans = 0;
    REP(i, N) {
        REP(j, N) {
            REP(k, N) {
                if (dp2[i][j][k] == INF)
                    continue;
                ans += dp2[i][j][k];
            }
        }
    }
    cout << ans << endl;
#if false
    while (true) {
        ll a, b, c;
        cin >> a >> b >> c;
        cout << dp2[a - 1][b - 1][c] << endl;
    }
#endif
    return 0;
}