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

const ll MOD = 998244353;
const ll INF = (ll) 2e9;

int main() {
    ll N;
    cin >> N;

    ll ans = 0;
    ll n = 0;
    while (n <= N) {
        // x^2-y == nとなる

        // n+1 <= x^2 <= n+Nとなるxの範囲を求める
        ll up = 0, ng = INF;
        while (abs(ng - up) > 1) {
            ll mid = (up + ng) / 2;
            if (mid * mid <= n + N)
                up = mid;
            else
                ng = mid;
        }

        ll low = INF;
        ng = -1;
        while (abs(low - ng) > 1) {
            ll mid = (low + ng) / 2;
            if (mid * mid >= n + 1)
                low = mid;
            else
                ng = mid;
        }

        ans += std::max(0LL, std::min(N, up) - std::max(low, 1LL) + 1);
        n++;
    }
    cout << ans << endl;
    return 0;
}