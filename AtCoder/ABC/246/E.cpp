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

ll x[4] = {1, 1, -1, -1};
ll y[4] = {1, -1, 1, -1};

struct Data {
    pll d;
    ll dir;
    ll cost;
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    pll s, g;
    cin >> s.first >> s.second;
    cin >> g.first >> g.second;
    s.first--;
    s.second--;
    g.first--;
    g.second--;
    vector<string> S(N);
    REP(i, N) {
        cin >> S[i];
    }

    vector<vector<vector<ll> >> D(N, vector<vector<ll>>(N, vector<ll>(4, INF)));
    REP(i, 4) {
        D[s.first][s.second][i] = 0;
    }
    priority_queue<Data, vector<Data>, function<bool(Data, Data)>> q([](Data a, Data b) { return a.cost > b.cost; });
    q.push(Data{s, -1, 0});
    while (!q.empty()) {
        Data t = q.top();
        q.pop();
        if (t.dir >= 0 && D[t.d.first][t.d.second][t.dir] < t.cost)
            continue;
        REP(i, 4) {
            ll cost = t.cost;
            if (i != t.dir)
                cost++;
            ll nx = t.d.first + x[i], ny = t.d.second + y[i];
            if (nx < 0 || ny < 0 || nx >= N || ny >= N)
                continue;
            if (S[nx][ny] == '#')
                continue;
            if (D[nx][ny][i] <= cost)
                continue;
            D[nx][ny][i] = cost;
            q.push(Data{pll(nx, ny), i, cost});
        }
    }

    ll ans = INF;
    REP(i, 4) {
        ans = std::min(D[g.first][g.second][i], ans);
    }
    if (ans == INF)
        ans = -1;
    cout << ans << endl;
    return 0;
}