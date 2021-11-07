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
    vector<ll> A(N);
    REP(i, N) {
        cin >> A[i];
    }
    ll min = INF;
    REP(i, N) {
        A[i] = A[i] - (i + 1);
        min = std::min(min, A[i]);
    }
    ll s = 0;
    REP(i, N) {
        s += A[i] - min;
        A[i] -= min;
    }
    ll ans = s;
    sort(A.begin(), A.end());
    ll m = 0;
    REP(i, N) {
        A[i] -= m;
        s = s + i * A[i] - (N - i) * A[i];
        ans = std::min(ans, s);
        m += A[i];
    }

    cout << ans << endl;
    return 0;
}