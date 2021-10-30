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
    ll H, N;
    cin >> H >> N;
    vector<pll> A(N);
    REP(i, N) {
        cin >> A[i].first >> A[i].second;
    }

    vector<ll> dp(H + 5, INF);
    dp[0] = 0;
    REP(i, N) {
        vector<ll> tmp(H + 5, INF);
        REP(j, dp.size()) {
            tmp[j] = std::min(tmp[j], dp[j]);
            ll nxt = std::min(H, j + A[i].first);
            tmp[nxt] = std::min(tmp[nxt], A[i].second + tmp[j]);
        }
        swap(dp, tmp);
    }

    cout << dp[H] << endl;
    return 0;
}