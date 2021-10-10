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
    ll N, K;
    cin >> N >> K;
    ll ans = 0;
    for (ll k = K; k <= N + 1; ++k) {
        // (0+1+...+k-1) ~ (N+N-1+N-2+...N-K+1)
        ll min = k * (k - 1) / 2;
        ll max = N * (N + 1) / 2 - ((N - k) * (N - k + 1) / 2);
        ans = (ans + max - min + 1) % MOD;
    }
    cout << ans << endl;
    return 0;
}