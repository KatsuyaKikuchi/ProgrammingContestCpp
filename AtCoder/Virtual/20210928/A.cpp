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

ll x[4] = {0, 1, 0, -1};
ll y[4] = {1, 0, -1, 0};

struct Data {
    pll g;
    char c;
};

int main() {
    ll H, W;
    cin >> H >> W;
    vector<string> S(H);
    REP(i, H) {
        cin >> S[i];
    }
    ll ans = 0;
    vector<vector<bool>> used(H, vector<bool>(W, false));
    REP(i, H) {
        REP(j, W) {
            if (used[i][j])
                continue;

            used[i][j] = true;
            ll b = 0, w = 0;
            queue<Data> q;
            q.push(Data{pll(i, j), S[i][j]});
            while (!q.empty()) {
                auto d = q.front();
                q.pop();

                if (d.c == '#')
                    b++;
                else
                    w++;
                REP(n, 4) {
                    ll nx = x[n] + d.g.first, ny = y[n] + d.g.second;
                    if (nx < 0 || ny < 0 || nx >= H || ny >= W)
                        continue;
                    if (used[nx][ny])
                        continue;
                    if (S[nx][ny] == d.c)
                        continue;
                    used[nx][ny] = true;
                    q.push(Data{pll(nx, ny), S[nx][ny]});
                }
            }

            ans += b * w;
        }
    }

    cout << ans << endl;
    return 0;
}