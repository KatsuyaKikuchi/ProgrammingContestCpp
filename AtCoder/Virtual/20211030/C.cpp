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

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll H, W, C;
    cin >> H >> W >> C;
    vector<vector<ll>> A(H, vector<ll>(W));
    REP(i, H) {
        REP(j, W) {
            cin >> A[i][j];
        }
    }
    vector<ll> M(W, INF);
    ll ans = INF;
    REP(i, H) {
        ll leftMin = M[0];
        priority_queue<pll, vector<pll>, function<bool(pll, pll)>> q([](pll a, pll b) { return a.first > b.first; });
        REP(j, W) {
            q.push(pll(M[j] + j * C, j));
        }
        q.push(pll(INF, W));
        REP(j, W) {
            while (!q.empty() && q.top().second < j) {
                q.pop();
            }
            ll cost = A[i][j] + std::min(leftMin, q.top().first - j * C);
            ans = std::min(ans, cost);

            leftMin = std::min({leftMin + C, A[i][j] + C, M[j] + C});
            M[j] = std::min(M[j] + C, A[i][j] + C);
        }
    }

    cout << ans << endl;
    return 0;
}