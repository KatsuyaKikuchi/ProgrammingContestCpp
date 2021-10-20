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
    vector<vector<ll>> A(N, vector<ll>(N));
    REP(i, N) {
        REP(j, N) {
            cin >> A[i][j];
        }
    }
    ll M;
    cin >> M;
    vector<vector<ll>> B(N, vector<ll>(N, 0));
    REP(i, M) {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        B[a][b] = B[b][a] = 1;
    }

    ll ans = INF;
    vector<ll> v;
    REP(i, N) {
        v.push_back(i);
    }

    do {
        ll cnt = 0;
        REP(i, v.size()) {
            cnt += A[v[i]][i];
            if (i < N - 1 && B[v[i]][v[i + 1]] > 0) {
                cnt = INF;
                break;
            }
        }
        ans = std::min(ans, cnt);
    } while (next_permutation(v.begin(), v.end()));

    if (ans == INF)
        ans = -1;
    cout << ans << endl;
    return 0;
}