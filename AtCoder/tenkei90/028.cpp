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

    ll N;
    cin >> N;
    ll MAX = 1005;
    vector<vector<ll>> M(MAX, vector<ll>(MAX, 0));
    REP(i, N) {
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        M[a][b]++;
        M[a][d]--;
        M[c][b]--;
        M[c][d]++;
    }

    REP(i, MAX) {
        REP(j, MAX - 1) {
            M[i][j + 1] += M[i][j];
        }
    }
    REP(i, MAX) {
        REP(j, MAX - 1) {
            M[j + 1][i] += M[j][i];
        }
    }
    vector<ll> ans(N + 1, 0);
    REP(i, MAX) {
        REP(j, MAX) {
            ans[M[i][j]]++;
        }
    }
    REP(i, N) {
        cout << ans[i + 1] << endl;
    }
    return 0;
}