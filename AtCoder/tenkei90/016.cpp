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

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, A, B, C;
    cin >> N >> A >> B >> C;
    ll ans = INF;
    REP(a, 10005) {
        ll n = a * A;
        if (n > N)
            break;
        REP(b, 10005) {
            ll m = n + b * B;
            if (m > N)
                break;
            if ((N - m) % C == 0)
                ans = std::min(a + b + (N - m) / C, ans);
        }
    }
    cout << ans << endl;
    return 0;
}