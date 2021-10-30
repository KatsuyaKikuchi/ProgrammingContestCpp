#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <queue>
#include <stack>
#include <iomanip>
#include <cmath>
#include <map>
#include <set>

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
    ll cost;
};

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

    vector<vector<ll>> A(H, vector<ll>(W, INF));
    priority_queue<Data, vector<Data>, function<bool(Data, Data)>> q([](Data a, Data b) { return a.cost > b.cost; });
    q.push(Data{pll(0, 0), 0});
    A[0][0] = 0;
    while (!q.empty()) {
        auto d = q.top();
        q.pop();
        if (A[d.g.first][d.g.second] < d.cost)
            continue;
        REP(i, 4) {
            ll nx = d.g.first + x[i], ny = d.g.second + y[i];
            if (nx < 0 || ny < 0 || nx >= H || ny >= W)
                continue;
            if (S[nx][ny] == '#')
                continue;
            if (A[nx][ny] <= d.cost)
                continue;
            A[nx][ny] = d.cost;
            q.push(Data{pll(nx, ny), d.cost});
        }
        // 壁を壊す
        for (ll i = -2; i <= 2; ++i) {
            for (ll j = -2; j <= 2; ++j) {
                if (abs(i) == 2 && abs(j) == 2)
                    continue;
                ll nx = d.g.first + i, ny = d.g.second + j;
                if (nx < 0 || ny < 0 || nx >= H || ny >= W)
                    continue;
                ll cost = d.cost + 1;
                if (A[nx][ny] <= cost)
                    continue;
                A[nx][ny] = cost;
                q.push(Data{pll(nx, ny), cost});
            }
        }
    }
    cout << A[H - 1][W - 1];
    return 0;
}