#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <queue>
#include <stack>
#include <iomanip>
#include <cmath>

using namespace std;
using ll = long long int;
using pll = pair<ll, ll>;

#define FOR(i, n, m) for(ll i = (m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;
const long double PI = 3.1415926535897932384626433832795028841971;

long double pi2rod(long double pi) {
    if (pi >= 0)
        return (pi / PI) * 180.0;
    return 360.0 - ((-pi / PI) * 180.0);
}

int main() {
    ll N;
    cin >> N;
    vector<pll> g(N);
    REP(i, N) {
        cin >> g[i].first >> g[i].second;
    }

    long double ans = 0;
    REP(i, N) {
        vector<long double> rod;
        REP(j, N) {
            if (i == j)
                continue;
            long double x = g[j].first - g[i].first;
            long double y = g[j].second - g[i].second;
            long double r = pi2rod(std::atan2(y, x));
            rod.push_back(r);
            rod.push_back(r + 360.0);
        }
        sort(rod.begin(), rod.end());
        REP(j, rod.size()) {
            ll ok = j, ng = rod.size();
            while (abs(ok - ng) > 1) {
                ll mid = (ok + ng) / 2;
                if (rod[mid] - rod[j] <= 180.0)
                    ok = mid;
                else
                    ng = mid;
            }
            long double mx = rod[ok] - rod[j];
            ans = std::max(ans, mx);
        }
    }
    cout << OF64 << ans << endl;
    return 0;
}