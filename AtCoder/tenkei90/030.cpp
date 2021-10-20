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
    ll N, K;
    cin >> N >> K;
    vector<ll> C(N + 10, 0);
    vector<bool> P(N + 10, true);
    for (ll i = 2; i <= N; ++i) {
        if (!P[i])
            continue;
        for (ll j = i; j <= N; j += i) {
            P[j] = false;
            C[j]++;
        }
    }

    ll ans = 0;
    REP(i, N + 1) {
        if (C[i] >= K)
            ans++;
    }
    cout << ans << endl;
    return 0;
}