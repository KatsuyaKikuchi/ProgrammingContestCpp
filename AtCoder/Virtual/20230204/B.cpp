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

struct Data {
    pll g;
    ll value;
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, M;
    cin >> N >> M;

    vector<ll> T(M + 5, -1);
    {
        ll t = 0;
        while (t * t <= M) {
            T[t * t] = t;
            t++;
        }
    }

    vector<vector<ll>> ans(N + 5, vector<ll>(N + 5, INF));
    ans[0][0] = 0;
    queue<Data> q;
    q.push(Data{pll(0, 0), 0});
    while (!q.empty()) {
        Data t = q.front();
        q.pop();
        if (ans[t.g.first][t.g.second] < t.value)
            continue;
        ll value = t.value + 1;
        REP(i, N) {
            ll d = M - (t.g.first - i) * (t.g.first - i);
            if (d < 0 || T[d] < 0)
                continue;
            pll nxt = pll(T[d] + t.g.second, -T[d] + t.g.second);
            if (nxt.first < N && nxt.first >= 0 && ans[i][nxt.first] > value) {
                q.push(Data{pll(i, nxt.first), value});
                ans[i][nxt.first] = value;
            }
            if (nxt.second < N && nxt.second >= 0 && ans[i][nxt.second] > value) {
                q.push(Data{pll(i, nxt.second), value});
                ans[i][nxt.second] = value;
            }
        }
    }

    REP(i, N) {
        REP(j, N) {
            ll o = ans[i][j];
            if (o == INF)
                o = -1;
            cout << o << " ";
        }
        cout << endl;
    }
    return 0;
}