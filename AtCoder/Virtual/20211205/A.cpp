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
    ll N, D;
    cin >> N >> D;
    vector<pll> A(N);
    REP(i, N) {
        cin >> A[i].first >> A[i].second;
    }
    sort(A.begin(), A.end(), [](pll a, pll b) { return a.second < b.second; });
    ll ans = 0;
    ll left = -INF;
    REP(i, N) {
        if (left + D - 1 >= A[i].first)
            continue;
        left = A[i].second;
        ans++;
    }
    cout << ans << endl;
    return 0;
}