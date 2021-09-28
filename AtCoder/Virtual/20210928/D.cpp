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
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

int main() {
    ll K;
    cin >> K;
    vector<ll> A(K);
    REP(i, K) {
        cin >> A[i];
    }
    reverse(A.begin(), A.end());
    if (A[0] != 2) {
        cout << -1 << endl;
        return 0;
    }
    pll ans(A[0], 2LL * A[0] - 1);
    FOR(i, K, 1) {
        ll min = ((ans.first + A[i] - 1) / A[i]) * A[i];
        ll max = (ans.second / A[i]) * A[i] + A[i] - 1;

        ans = pll(min, max);
    }

    if (ans.first > ans.second)
        cout << -1 << endl;
    else
        cout << ans.first << " " << ans.second << endl;
    return 0;
}