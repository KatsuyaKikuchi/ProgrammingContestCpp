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
    ll N, M;
    cin >> N >> M;
    vector<ll> P(M, false);
    REP(i, N) {
        ll a, b;
        cin >> a >> b;
        ll s = i - (a + b);
        if (s < 0 || s >= M)
            continue;
        P[s] = true;
    }
    ll ans = 0;
    REP(i, M) {
        if (P[i])
            ans++;
    }
    cout << ans << endl;
    return 0;
}