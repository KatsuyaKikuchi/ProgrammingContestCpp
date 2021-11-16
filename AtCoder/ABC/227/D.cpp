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
const ll INF = (ll) 1e18;
const long double PI = 3.1415926535897932384626433832795028841971;
ll N, K;
vector<ll> A;

bool solve(ll m) {
    ll sum = 0;
    REP(i, N) {
        sum += std::min(A[i], m);
    }
    return sum / K >= m;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> N >> K;
    A.resize(N);
    REP(i, N) {
        cin >> A[i];
    }
    sort(A.begin(), A.end(), greater<ll>());
    ll ans = 0, ng = INF;
    while (abs(ans - ng) > 1) {
        ll mid = (ans + ng) / 2;
        if (solve(mid))
            ans = mid;
        else ng = mid;
    }
    cout << ans << endl;
    return 0;
}