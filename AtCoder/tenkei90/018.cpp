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

long double T, L, X, Y;

long double solve(long double t) {
    long double theta = (2.0 * t / T) * PI;
    long double y = -L * 0.5 * sin(theta);
    long double z = L * 0.5 * (1 - cos(theta));
    long double len = sqrt(X * X + (Y - y) * (Y - y));

    long double ret = atan2(z, len) / PI;
    return ret * 180;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> T >> L >> X >> Y;
    ll Q;
    cin >> Q;
    REP(_, Q) {
        long double t;
        cin >> t;
        cout << OF64 << solve(t) << endl;
    }
    return 0;
}