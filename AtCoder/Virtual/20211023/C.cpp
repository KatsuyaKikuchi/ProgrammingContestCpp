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

ll N, M;
vector<ll> X;

bool check(ll m) {
    ll left = 1;
    REP(i, M) {
        if (left < X[i]) {
            ll t = X[i] - left;
            if (t > m)
                return false;
            ll nxt = std::max({X[i] + 1, left + (m - t) + 1, X[i] + ((m - t) / 2) + 1});
            left = nxt;
        } else {
            left = std::max(left, X[i] + m + 1);
        }
    }

    return left > N;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> N >> M;
    X.resize(M);
    REP(i, M) {
        cin >> X[i];
    }
    sort(X.begin(), X.end());

    ll ans = 5 * N, ng = -1;
    while (abs(ans - ng) > 1) {
        ll mid = (ans + ng) / 2;
        if (check(mid))
            ans = mid;
        else
            ng = mid;
    }

    cout << ans << endl;

    return 0;
}